SELECT
             + self.yesterdayint +                AS data_date            ,
             + self.currentday_year+                        AS data_year            ,
             + self.currentday_month+                        AS data_month           ,
             + self.currentday_week+                        AS data_week            ,
             + self.currentday_day+                        AS data_day             ,
            sku_and_ord.data_type              AS data_type            ,
            sku_and_ord.brand_code             AS brand_code           ,
            sku_and_ord.barndname_full         AS barndname_full       ,
            sku_and_ord.item_first_cate_cd     AS item_first_cate_cd   ,
            sku_and_ord.item_first_cate_name   AS item_first_cate_name ,
            sku_and_ord.item_second_cate_cd    AS item_second_cate_cd  ,
            sku_and_ord.item_second_cate_name  AS item_second_cate_name,
            sku_and_ord.item_third_cate_cd     AS item_third_cate_cd   ,
            sku_and_ord.item_third_cate_name   AS item_third_cate_name ,
            sku_and_ord.thirdcate_brand            as thirdcate_brand,
            sku_and_ord.item_sku_id            AS item_sku_id          ,
            sku_and_ord.sku_name            AS sku_name          ,
            NULL                       AS dept_id_1            ,
            NULL                       AS dept_name_1          ,
            NULL                       AS dept_id_2            ,
            NULL                       AS dept_name_2          ,
            sku_and_ord.dept_id_3           AS dept_id_3            ,
            NULL                       AS dept_name_3          ,

            sku_and_ord.sale_qtty              AS sale_qtty            ,
            sku_and_ord.sale_amount AS sale_amount,
            log.total_uv  AS total_uv            ,
            log.total_pv   AS total_pv
        from
        (
        SELECT

            sku.data_type              AS data_type            ,
            sku.brand_code             AS brand_code           ,
            sku.barndname_full         AS barndname_full       ,
            sku.item_first_cate_cd     AS item_first_cate_cd   ,
            sku.item_first_cate_name   AS item_first_cate_name ,
            sku.item_second_cate_cd    AS item_second_cate_cd  ,
            sku.item_second_cate_name  AS item_second_cate_name,
            sku.item_third_cate_cd     AS item_third_cate_cd   ,
            sku.item_third_cate_name   AS item_third_cate_name ,
            concat(sku.item_third_cate_cd, '_' ,sku.brand_code)            as thirdcate_brand,
            sku.item_sku_id            AS item_sku_id          ,
            sku.sku_name            AS sku_name          ,

            sku.work_post_cd           AS dept_id_3            ,


            ord.sale_qtty              AS sale_qtty            ,
            ord.after_prefr_amount AS sale_amount
         FROM

            (
                    SELECT
                            item_sku_id          ,
                            sku_name        ,
                            data_type            ,
                            brand_code           ,
                            barndname_full       ,
                            item_first_cate_cd   ,
                            item_first_cate_name ,
                            item_second_cate_cd  ,
                            item_second_cate_name,
                            item_third_cate_cd   ,
                            item_third_cate_name ,
                            work_post_cd
                    FROM
                            gdm.gdm_m03_item_sku_da
                    WHERE
                            dt            = ' + self.yesterday + '
                            AND (data_type = 1
                            OR
                            (
                                    data_type              = 3
                                    AND item_first_cate_cd = '737'
                            )
                            )
                            AND sku_valid_flag = 1
                            AND sku_status_cd  = 3001
            )
            sku
         INNER JOIN
            (
                    SELECT
                            item_sku_id                             ,


                            COALESCE(Sum(sale_qtty), 0)              AS sale_qtty,
                            COALESCE(Sum(after_prefr_amount), 0) AS
                            after_prefr_amount
                    FROM
                            gdm.gdm_m04_ord_det_sum
                    WHERE
                            dt                                >= ' + self.realyesterday + '
                            AND Substr(sale_ord_dt, 0, 10) = ' + self.yesterday + '
                            AND sale_ord_valid_flag            = 1
                    GROUP BY
                            item_sku_id
            )
            ord
         ON
            sku.item_sku_id = ord.item_sku_id
            ) sku_and_ord
            left outer join
  (SELECT                                      sku_id as item_sku_id,
                                               total_uv AS total_uv,
                                               total_pv AS total_pv
                                        FROM   (
                                               select temp1.sku_id,
                                                      temp1.total_uv,
                                                      temp2.total_pv
                                                from
                                                  (SELECT sku_id,
                                                       Coalesce(Count(distinct browser_uniq_id), 0) AS total_uv
                                                FROM   gdm.gdm_online_log
                                                WHERE  dt = ' + self.yesterday + '
                                                       AND sku_id IS NOT NULL
                                                GROUP  BY sku_id) temp1
                                                          left outer join
                                                          (
                                                        SELECT sku_id,
                                                       Coalesce(Count(user_visit_ip), 0) AS total_pv
                                                FROM   gdm.gdm_online_log
                                                WHERE  dt = ' + self.yesterday + '
                                                       AND sku_id IS NOT NULL
                                                GROUP  BY sku_id
                                                          ) temp2 on temp1.sku_id=temp2.sku_id
                                                          ) log_det
                                        ) log  on  sku_and_ord.item_sku_id=log.item_sku_id
