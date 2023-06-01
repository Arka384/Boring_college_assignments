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

ALTER TABLE `EMP` CHANGE COLUMN `ECODE` EMPLOYEE CODE VARCHAR(16);

ALTER TABLE EMP
CHANGE COLUMN 'ECODE'
                EMPLOYEE CODE
                VARCHAR(16);

select * from EMP;

/*
3. Set the format of columns as mentioned below, So that in subsequent SELECT statement ,values
appear in the specified format:
*format of BASIC is such that a value of 7000 will be shown as7,000
*Format of GRADE will be such that full column name
appears in the display.
*For JN-DT format is such that 01-JAN-00 will be shown as JANURY 01,2000
*/
SELECT
    `EMPLOYEE CODE`,
    `NAME`,
   `DEPT.CODE`,
    FORMAT(BASIC, 0) as BASIC,
	GRADE,
    date_format(`JOINING DATE`, '%M-%d-%Y') as `JN-DT`
FROM EMP;

/*
6. Drop all the tables that you have created .
*/
DROP TABLE EMP;
