create database assg4;
use assg4;

drop database assg4;

/* 1
a) Create EMP table with ECODE(primary key), ENAME, DCODE, GRADE, BASIC &amp; JN-DT as the
columns.[except BASIC &amp; JN-DT,all columns are of char type and site of Grade is 1.]
b)Insert number of rows.
*/
CREATE TABLE EMP (
    ECODE VARCHAR(16) PRIMARY KEY,
    ENAME VARCHAR(50),
    DCODE VARCHAR(16),
    GRADE CHAR(1),
    BASIC INTEGER,
    JN_DT DATE
);
INSERT INTO EMP (ECODE, ENAME, DCODE, GRADE, BASIC, JN_DT)
VALUES
    ('E001', 'John Doe', 'D001', 'A', 5000, '2022-01-01'),
    ('E002', 'Jane Smith', 'D002', 'B', 6000, '2022-02-15'),
    ('E003', 'Mike Johnson', 'D001', 'A', 5500, '2022-03-10'),
    ('E004', 'Emily Davis', 'D002', 'B', 7000, '2022-04-05'),
    ('E005', 'David Wilson', 'D003', 'A', 6500, '2022-05-20'),
    ('E006', 'Sarah Thompson', 'D003', 'B', 5500, '2022-06-12'),
    ('E007', 'Michael Brown', 'D001', 'C', 4800, '2022-07-03');

MariaDB [assignment_4]> SELECT * FROM EMP;
+-------+----------------+-------+-------+-------+------------+
| ECODE | ENAME          | DCODE | GRADE | BASIC | JN_DT      |
+-------+----------------+-------+-------+-------+------------+
| E001  | John Doe       | D001  | A     |  5000 | 2022-01-01 |
| E002  | Jane Smith     | D002  | B     |  6000 | 2022-02-15 |
| E003  | Mike Johnson   | D001  | A     |  5500 | 2022-03-10 |
| E004  | Emily Davis    | D002  | B     |  7000 | 2022-04-05 |
| E005  | David Wilson   | D003  | A     |  6500 | 2022-05-20 |
| E006  | Sarah Thompson | D003  | B     |  5500 | 2022-06-12 |
| E007  | Michael Brown  | D001  | C     |  4800 | 2022-07-03 |
+-------+----------------+-------+-------+-------+------------+


/* 2
	change the column heading as shown below, So that in subsequent SELECT statement newly set
	heading will be shown:
	ECODE EMPLOYEE CODE
	ENAME NAME
	DCODE DEPT.CODE
	JN-DT JONING DATE
*/

ALTER TABLE EMP
RENAME COLUMN ECODE TO `EMPLOYEE CODE`,
RENAME COLUMN ENAME TO `NAME`,
RENAME COLUMN DCODE TO `DEPT.CODE`,
RENAME COLUMN JN_DT TO `JOINING DATE`;

MariaDB [assignment_4]> SELECT * FROM EMP;
+---------------+----------------+-----------+-------+-------+--------------+
| EMPLOYEE CODE | NAME           | DEPT.CODE | GRADE | BASIC | JOINING DATE |
+---------------+----------------+-----------+-------+-------+--------------+
| E001 		    | John Doe       | D001  	 | A     |  5000 | 2022-01-01 	|
| E002  		| Jane Smith     | D002  	 | B     |  6000 | 2022-02-15 	|
| E003  		| Mike Johnson   | D001  	 | A     |  5500 | 2022-03-10 	|
| E004  		| Emily Davis    | D002  	 | B     |  7000 | 2022-04-05 	|
| E005  		| David Wilson   | D003  	 | A     |  6500 | 2022-05-20 	|
| E006  		| Sarah Thompson | D003  	 | B     |  5500 | 2022-06-12 	|
| E007  		| Michael Brown  | D001  	 | C     |  4800 | 2022-07-03 	|
+---------------+----------------+-----------+-------+-------+--------------+

/*
3. Set the format of columns as mentioned below, So that in subsequent SELECT statement ,values
appear in the specified format:
*format of BASIC is such that a value of 7000 will be shown as7,000
*Format of GRADE will be such that full column name
appears in the display.
*For JN-DT format is such that 01-JAN-00 will be shown as JANURY 01,2000
*/
SELECT
	ECODE,
	ENAME,
	DCODE,
	FORMAT(BASIC, 0) as BASIC,
	GRADE,
    date_format(JN_DT, '%M-%d-%Y') as JN-DT
FROM EMP;

MariaDB [assignment_4]> SELECT ECODE, ENAME, DCODE,
    -> FORMAT(BASIC, 0) AS BASIC,
    -> GRADE,
    -> DATE_FORMAT(JN_DT, '%M-%d-%Y') AS JN_DT
    -> FROM EMP;
+-------+----------------+-------+-------+-------+------------------+
| ECODE | ENAME          | DCODE | BASIC | GRADE | JN_DT            |
+-------+----------------+-------+-------+-------+------------------+
| E001  | John Doe       | D001  | 5,000 | A     | January-01-2022  |
| E002  | Jane Smith     | D002  | 6,000 | B     | February-15-2022 |
| E003  | Mike Johnson   | D001  | 5,500 | A     | March-10-2022    |
| E004  | Emily Davis    | D002  | 7,000 | B     | April-05-2022    |
| E005  | David Wilson   | D003  | 6,500 | A     | May-20-2022      |
| E006  | Sarah Thompson | D003  | 5,500 | B     | June-12-2022     |
| E007  | Michael Brown  | D001  | 4,800 | C     | July-03-2022     |
+-------+----------------+-------+-------+-------+------------------+


/*
	///////////
	4 ///////////////////
	//////////
*/

DESC EMP;
MariaDB [assignment_4]> DESC EMP;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| ECODE | varchar(16) | NO   | PRI | NULL    |       |
| ENAME | varchar(50) | YES  |     | NULL    |       |
| DCODE | varchar(16) | YES  |     | NULL    |       |
| GRADE | char(1)     | YES  |     | NULL    |       |
| BASIC | int(11)     | YES  |     | NULL    |       |
| JN_DT | date        | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+


DESC EMP ENAME;
MariaDB [assignment_4]> DESC EMP ENAME;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| ENAME | varchar(50) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+


ALTER TABLE EMP MODIFY COLUMN JOINING_DATE DATE FORMAT 'YYYY-MM-DD';
ALTER TABLE EMP MODIFY COLUMN EMPLOYEE_CODE INT;
ALTER TABLE EMP MODIFY COLUMN NAME VARCHAR(20);
ALTER TABLE EMP MODIFY COLUMN DEPARTMENT_CODE CHAR(1);
ALTER TABLE EMP MODIFY COLUMN GRADE CHAR(1);
ALTER TABLE EMP MODIFY COLUMN BASIC FLOAT;
ALTER TABLE EMP MODIFY COLUMN JOINING_DATE DATE;

MariaDB [ASSIGNMENT_4]> DESC EMP;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| ECODE | int(1)      | NO   | PRI | NULL    |       |
| ENAME | varchar(20) | YES  |     | NULL    |       |
| DCODE | varchar(10) | YES  |     | NULL    |       |
| GRADE | char(1)     | YES  |     | NULL    |       |
| BASIC | float       | YES  |     | NULL    |       |
| JN_DT | date        | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+



