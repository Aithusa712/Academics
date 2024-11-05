DROP TABLE tbl_Fact;

CREATE TABLE tbl_Fact (
sale_ID 	NUMBER GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1),
dim_1_id	NUMBER NOT NULL,
dim_2_id	NUMBER NOT NULL,
dim_3_id  	NUMBER NOT NULL,
dim_4_id  	NUMBER NOT NULL,
sale_total	NUMBER(10,2) NOT NULL,
CONSTRAINT fact_pk PRIMARY KEY (sale_ID));


INSERT INTO tbl_Fact (dim_1_id, dim_2_id, dim_3_id, dim_4_id, sale_total)
SELECT 
	TRUNC(DBMS_RANDOM.value(low => 1, high =>3)) AS dim_1_id,
	TRUNC(DBMS_RANDOM.value(low =>1, high =>6)) AS dim_2_id,
	TRUNC(DBMS_RANDOM.value(low =>1, high =>11)) AS dim_3_id,
	TRUNC(DBMS_RANDOM.value(Low =>1, high =>11)) AS dim_4_id,
	ROUND(DBMS_RANDOM.value(low =>1, high =>100),2) AS sale_total
FROM dual
CONNECT BY level <= 1000;

COMMIT;

SELECT SUM(sale_total) as TOTAL_SALES
FROM tbl_fact;


/*Group by*/
SELECT dim_1_id, COUNT(*) as num_rows, SUM(sale_total) as TOTAL_SALES
FROM tbl_fact
GROUP BY dim_1_id;


/*Rollup*/
SELECT dim_1_id, dim_2_id, SUM(sale_total) as TOTAL_SALES FROM tbl_fact
GROUP BY ROLLUP (dim_1_id, dim_2_id)
ORDER BY dim_1_id, dim_2_id;

