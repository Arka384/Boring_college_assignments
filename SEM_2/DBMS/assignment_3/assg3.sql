create database assg3;
use assg3;

drop database assg3;

CREATE TABLE DEPARTMENT (
    DEPT_CODE VARCHAR(16) PRIMARY KEY,
    DEPT_NAME VARCHAR(50) NOT NULL
);

MariaDB [assignment_3]> DESC DEPARTMENT;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| DEPT_CODE | varchar(16) | NO   | PRI | NULL    |       |
| DEPT_NAME | varchar(50) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+


CREATE TABLE EMPLOYEE (
    EMP_CODE VARCHAR(16) PRIMARY KEY,
    EMP_NAME VARCHAR(50) CHECK (EMP_NAME = upper(EMP_NAME)),
    DEPT_CODE VARCHAR(16) NOT NULL,
    SEX CHAR(1) CHECK (SEX IN ('M', 'F')),
    ADDRESS VARCHAR(100),
    CITY VARCHAR(50),
    STATE VARCHAR(50),
    PIN INTEGER,
    BASIC INTEGER CHECK (BASIC BETWEEN 5000 AND 9000),
    JN_DT DATE DEFAULT (current_date()),
    GRADE CHAR(1) CHECK (GRADE IN ('A', 'B', 'C')),
	FOREIGN KEY (DEPT_CODE)
        REFERENCES DEPARTMENT (DEPT_CODE)
        ON DELETE RESTRICT
);

MariaDB [assignment_3]> DESC EMPLOYEE;
+-----------+--------------+------+-----+-----------+-------+
| Field     | Type         | Null | Key | Default   | Extra |
+-----------+--------------+------+-----+-----------+-------+
| EMP_CODE  | varchar(16)  | NO   | PRI | NULL      |       |
| EMP_NAME  | varchar(50)  | YES  |     | NULL      |       |
| DEPT_CODE | varchar(16)  | NO   | MUL | NULL      |       |
| SEX       | char(1)      | YES  |     | NULL      |       |
| ADDRESS   | varchar(100) | YES  |     | NULL      |       |
| CITY      | varchar(50)  | YES  |     | NULL      |       |
| STATE     | varchar(50)  | YES  |     | NULL      |       |
| PIN       | int(11)      | YES  |     | NULL      |       |
| BASIC     | int(11)      | YES  |     | NULL      |       |
| JN_DT     | date         | YES  |     | curdate() |       |
| GRADE     | char(1)      | YES  |     | NULL      |       |
+-----------+--------------+------+-----+-----------+-------+


CREATE TABLE LEAVE_RECORD (
    LEAVE_ID INTEGER PRIMARY KEY,
    EMP_CODE VARCHAR(16) NOT NULL,
    LEAVE_TYPE VARCHAR(10) CHECK (LEAVE_TYPE IN ('CL', 'EL', 'ML')),
    FROM_DATE DATE,
    TO_DATE DATE,
	FOREIGN KEY (EMP_CODE)
        REFERENCES EMPLOYEE (EMP_CODE)
        ON DELETE CASCADE
);

MariaDB [assignment_3]> DESC LEAVE_RECORD;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| LEAVE_ID   | int(11)     | NO   | PRI | NULL    |       |
| EMP_CODE   | varchar(16) | NO   | MUL | NULL    |       |
| LEAVE_TYPE | varchar(10) | YES  |     | NULL    |       |
| FROM_DATE  | date        | YES  |     | NULL    |       |
| TO_DATE    | date        | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+



INSERT INTO DEPARTMENT (DEPT_CODE, DEPT_NAME)
VALUES
	('D001', 'Sales'),
	('D002', 'Marketing'),
	('D003', 'Finance');

MariaDB [assignment_3]> SELECT * FROM DEPARTMENT;
+-----------+-----------+
| DEPT_CODE | DEPT_NAME |
+-----------+-----------+
| D001      | Sales     |
| D002      | Marketing |
| D003      | Finance   |
+-----------+-----------+


INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DEPT_CODE, SEX, ADDRESS, CITY, STATE, PIN, BASIC, GRADE)
VALUES
    ('E0010', 'John Doe', 'D001', 'M', '123 Main St', 'New York', 'NY', 12345, 6000, 'A'),
    ('E0011', 'Jane Smith', 'D001', 'F', '456 Elm St', 'Los Angeles', 'CA', 67890, 7000, 'B'),
    ('E0012', 'Michael Johnson', 'D002', 'M', '789 Oak St', 'Chicago', 'IL', 98765, 8000, 'C'),
    ('E0013', 'Emily Brown', 'D002', 'F', '321 Pine St', 'Houston', 'TX', 54321, 5500, 'A'),
    ('E0014', 'David Wilson', 'D003', 'M', '654 Cedar St', 'Miami', 'FL', 13579, 9000, 'B');

MariaDB [assignment_3]> SELECT * FROM EMPLOYEE;
+----------+-----------------+-----------+------+--------------+-------------+-------+-------+-------+------------+-------+
| EMP_CODE | EMP_NAME        | DEPT_CODE | SEX  | ADDRESS      | CITY        | STATE | PIN   | BASIC | JN_DT      | GRADE |
+----------+-----------------+-----------+------+--------------+-------------+-------+-------+-------+------------+-------+
| E0010    | John Doe        | D001      | M    | 123 Main St  | New York    | NY    | 12345 |  6000 | 2023-06-10 | A     |
| E0011    | Jane Smith      | D001      | F    | 456 Elm St   | Los Angeles | CA    | 67890 |  7000 | 2023-06-10 | B     |
| E0012    | Michael Johnson | D002      | M    | 789 Oak St   | Chicago     | IL    | 98765 |  8000 | 2023-06-10 | C     |
| E0013    | Emily Brown     | D002      | F    | 321 Pine St  | Houston     | TX    | 54321 |  5500 | 2023-06-10 | A     |
| E0014    | David Wilson    | D003      | M    | 654 Cedar St | Miami       | FL    | 13579 |  9000 | 2023-06-10 | B     |
+----------+-----------------+-----------+------+--------------+-------------+-------+-------+-------+------------+-------+



INSERT INTO LEAVE_RECORD (LEAVE_ID, EMP_CODE, LEAVE_TYPE, FROM_DATE, TO_DATE)
VALUES
    (1, 'E0010', 'CL', '2023-02-01', '2023-02-02'),
    (2, 'E0011', 'EL', '2023-03-15', '2023-03-20'),
    (3, 'E0012', 'ML', '2023-04-10', '2023-04-15'),
    (4, 'E0013', 'CL', '2023-05-10', '2023-05-10'),
    (5, 'E0014', 'EL', '2023-06-01', '2023-06-05');

MariaDB [assignment_3]> SELECT * FROM LEAVE_RECORD;
+----------+----------+------------+------------+------------+
| LEAVE_ID | EMP_CODE | LEAVE_TYPE | FROM_DATE  | TO_DATE    |
+----------+----------+------------+------------+------------+
|        1 | E0010    | CL         | 2023-02-01 | 2023-02-02 |
|        2 | E0011    | EL         | 2023-03-15 | 2023-03-20 |
|        3 | E0012    | ML         | 2023-04-10 | 2023-04-15 |
|        4 | E0013    | CL         | 2023-05-10 | 2023-05-10 |
|        5 | E0014    | EL         | 2023-06-01 | 2023-06-05 |
+----------+----------+------------+------------+------------+

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


-- 2 Try to violate the constraints that you have implemented in the table &amp; note, what happens. [Try with suitable INSERT/UPDATE/DELETE instruction]
-- violate foriegn key integrity constraint
INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DEPT_CODE, SEX, BASIC) 
VALUES ('E002', 'john doe', 'D0010', 'M', 5500);

MariaDB [assignment_3]> INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DEPT_CODE, SEX, BASIC)
    -> VALUES ('E002', 'john doe', 'D0010', 'M', 5500);
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails 
(`assignment_3`.`employee`, CONSTRAINT `employee_ibfk_1` FOREIGN KEY (`DEPT_CODE`) REFERENCES `department` (`DEPT_CODE`))
-- salary range violated

INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DEPT_CODE, SEX, BASIC)
VALUES ('E002', 'Jane Smith', 'D002', 'F', 9500);

MariaDB [assignment_3]> INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DEPT_CODE, SEX, BASIC)
    -> VALUES ('E002', 'Jane Smith', 'D002', 'F', 9500);
ERROR 4025 (23000): CONSTRAINT `employee.BASIC` failed for `assignment_3`.`employee`


-- grade range violated
INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DEPT_CODE, SEX, BASIC, GRADE)
VALUES ('E002', 'Jane Smith', 'D002', 'F', 9500, 'D');

MariaDB [assignment_3]> INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DEPT_CODE, SEX, BASIC, GRADE)
    -> VALUES ('E002', 'Jane Smith', 'D002', 'F', 9500, 'D');
ERROR 4025 (23000): CONSTRAINT `employee.BASIC` failed for `assignment_3`.`employee`

-- salary range violated
INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DEPT_CODE, SEX, BASIC, GRADE)
VALUES ('E002', 'jane Smith', 'D002', 'F', 3000, 'C');

MariaDB [assignment_3]> INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DEPT_CODE, SEX, BASIC, GRADE)
    -> VALUES ('E002', 'jane Smith', 'D002', 'F', 3000, 'C');
ERROR 4025 (23000): CONSTRAINT `employee.BASIC` failed for `assignment_3`.`employee`

-- using update
select * from employee;
update employee 
set DEPT_CODE = 'D010'
where emp_code = 'E0010';

MariaDB [assignment_3]> update employee
    -> set DEPT_CODE = 'D010'
    -> where emp_code = 'E0010';
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails 
(`assignment_3`.`employee`, CONSTRAINT `employee_ibfk_1` FOREIGN KEY (`DEPT_CODE`) REFERENCES `department` (`DEPT_CODE`))

-- delete 
DELETE FROM DEPARTMENT WHERE DEPT_CODE = 'D0010';

MariaDB [assignment_3]> DELETE FROM DEPARTMENT WHERE DEPT_CODE = 'D0010';
Query OK, 0 rows affected (0.001 sec)

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

/*
3. a) create a view showing employee code, name, dcode, Basic For a particular department.
b)Try to ensure a row into the view with valid department &amp; also with invalid ones.
c)Find the newly inserted row in the table From which view was created .
d) Try to increment basic by Rs.100/-
e) Check it in the original table.
f) Delete the view.
*/
-- a
CREATE VIEW EmployeeView AS
SELECT EMP_CODE, EMP_NAME, DEPT_CODE, BASIC
FROM EMPLOYEE
WHERE DEPT_CODE = 'D001';

MariaDB [assignment_3]> CREATE VIEW EmployeeView AS
    -> SELECT EMP_CODE, EMP_NAME, DEPT_CODE, BASIC
    -> FROM EMPLOYEE
    -> WHERE DEPT_CODE = 'D001';
Query OK, 0 rows affected

MariaDB [assignment_3]> SELECT * FROM EMPLOYEEVIEW;
+----------+------------+-----------+-------+
| EMP_CODE | EMP_NAME   | DEPT_CODE | BASIC |
+----------+------------+-----------+-------+
| E0010    | John Doe   | D001      |  6000 |
| E0011    | Jane Smith | D001      |  7000 |
+----------+------------+-----------+-------+

-- b
INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DEPT_CODE, SEX, BASIC, GRADE)
VALUES ('E003', 'janey Smith', 'D001', 'F', 8000, 'C');

MariaDB [assignment_3]> INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DEPT_CODE, SEX, BASIC,
    -> VALUES ('E003', 'janey Smith', 'D001', 'F', 8000, 'C');
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds 
to your MariaDB server version for the right syntax to use near 'VALUES 
('E003', 'janey Smith', 'D001', 'F', 8000, 'C')' at line 2


select * from EMPLOYEEVIEW;

SELECT * FROM EMPLOYEE, EMPLOYEEVIEW
WHERE EMPLOYEE.EMP_CODE = EMPLOYEEVIEW.EMP_CODE;

MariaDB [assignment_3]> SELECT * FROM EMPLOYEE, EMPLOYEEVIEW
    -> WHERE EMPLOYEE.EMP_CODE = EMPLOYEEVIEW.EMP_CODE;
+----------+------------+-----------+------+-------------+-------------+-------+-------+-------+------------+-------+----------+------------+-----------+-------+
| EMP_CODE | EMP_NAME   | DEPT_CODE | SEX  | ADDRESS     | CITY        | STATE | PIN   | BASIC | JN_DT      | GRADE | EMP_CODE | EMP_NAME   | DEPT_CODE | BASIC |
+----------+------------+-----------+------+-------------+-------------+-------+-------+-------+------------+-------+----------+------------+-----------+-------+
| E0010    | John Doe   | D001      | M    | 123 Main St | New York    | NY    | 12345 |  6000 | 2023-06-10 | A     | E0010    | John Doe   | D001      |  6000 |
| E0011    | Jane Smith | D001      | F    | 456 Elm St  | Los Angeles | CA    | 67890 |  7000 | 2023-06-10 | B     | E0011    | Jane Smith | D001      |  7000 |
+----------+------------+-----------+------+-------------+-------------+-------+-------+-------+------------+-------+----------+------------+-----------+-------+

-- c
UPDATE EMPLOYEE
SET BASIC = BASIC + 100
WHERE DEPT_CODE = 'D001';

MariaDB [assignment_3]> UPDATE EMPLOYEE SET BASIC = BASIC + 100 WHERE DEPT_CODE = 'D001';
Query OK, 2 rows affected (0.003 sec)
Rows matched: 2  Changed: 2  Warnings: 0

MariaDB [assignment_3]> SELECT * FROM EMPLOYEE;
+----------+-----------------+-----------+------+--------------+-------------+-------+-------+-------+------------+-------+
| EMP_CODE | EMP_NAME        | DEPT_CODE | SEX  | ADDRESS      | CITY        | STATE | PIN   | BASIC | JN_DT      | GRADE |
+----------+-----------------+-----------+------+--------------+-------------+-------+-------+-------+------------+-------+
| E0010    | John Doe        | D001      | M    | 123 Main St  | New York    | NY    | 12345 |  6100 | 2023-06-10 | A     |
| E0011    | Jane Smith      | D001      | F    | 456 Elm St   | Los Angeles | CA    | 67890 |  7100 | 2023-06-10 | B     |
| E0012    | Michael Johnson | D002      | M    | 789 Oak St   | Chicago     | IL    | 98765 |  8000 | 2023-06-10 | C     |
| E0013    | Emily Brown     | D002      | F    | 321 Pine St  | Houston     | TX    | 54321 |  5500 | 2023-06-10 | A     |
| E0014    | David Wilson    | D003      | M    | 654 Cedar St | Miami       | FL    | 13579 |  9000 | 2023-06-10 | B     |
+----------+-----------------+-----------+------+--------------+-------------+-------+-------+-------+------------+-------+
-- e
DROP VIEW EmployeeView;

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


/* 4
a) create a view Showing empcode, name, deptname, basic, leave type, From date &amp; to date.
b)Try to insert a row in the view. Check what happens?
c) Try to increment basic by Rs.100.
d) Delete the view.
*/

-- a
CREATE VIEW EMPLOYEELEAVEVIEW AS
SELECT EMPLOYEE.EMP_CODE, EMPLOYEE.EMP_NAME, DEPARTMENT.DEPT_NAME, EMPLOYEE.BASIC, 
LEAVE_RECORD.LEAVE_TYPE, LEAVE_RECORD.FROM_DATE, LEAVE_RECORD.TO_DATE
FROM EMPLOYEE, DEPARTMENT, LEAVE_RECORD
WHERE EMPLOYEE.DEPT_CODE = DEPARTMENT.DEPT_CODE
AND EMPLOYEE.EMP_CODE = LEAVE_RECORD.EMP_CODE;

select * from EMPLOYEELEAVEVIEW;

MariaDB [assignment_3]> select * from EMPLOYEELEAVEVIEW;
+----------+-----------------+-----------+-------+------------+------------+------------+
| EMP_CODE | EMP_NAME        | DEPT_NAME | BASIC | LEAVE_TYPE | FROM_DATE  | TO_DATE    |
+----------+-----------------+-----------+-------+------------+------------+------------+
| E0010    | John Doe        | Sales     |  6100 | CL         | 2023-02-01 | 2023-02-02 |
| E0011    | Jane Smith      | Sales     |  7100 | EL         | 2023-03-15 | 2023-03-20 |
| E0012    | Michael Johnson | Marketing |  8000 | ML         | 2023-04-10 | 2023-04-15 |
| E0013    | Emily Brown     | Marketing |  5500 | CL         | 2023-05-10 | 2023-05-10 |
| E0014    | David Wilson    | Finance   |  9000 | EL         | 2023-06-01 | 2023-06-05 |
+----------+-----------------+-----------+-------+------------+------------+------------+

-- b
insert into EmployeeLeaveView (EMP_CODE, EMP_NAME, DEPT_NAME, BASIC, LEAVE_TYPE, FROM_DATE, TO_DATE)
values
('E0015', 'jon snow', 'Sales', 7000, 'CL', '2023-02-01', '2023-02-02' );

MariaDB [assignment_3]> insert into EmployeeLeaveView (EMP_CODE, EMP_NAME, DEPT_NAME, BASIC, LEAVE_TYPE, FROM_DATE, TO_DATE)
    -> values
    -> ('E0015', 'jon snow', 'Sales', 7000, 'CL', '2023-02-01', '2023-02-02' );
ERROR 1393 (HY000): Can not modify more than one base table through a join view 'assignment_3.employeeleaveview'

-- c 
UPDATE EMPLOYEE
SET BASIC = BASIC + 100;

MariaDB [assignment_3]> UPDATE EMPLOYEE SET BASIC = BASIC + 100;
ERROR 4025 (23000): CONSTRAINT `employee.BASIC` failed for `assignment_3`.`employee`

-- d
DROP VIEW EmployeeLeaveView;

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


/* 5
a) Create a table having empcode , Name, deptname, &amp; basic From the existing tables along with the
records of the employee who are in a particular department (say, d1) and with a basic Rs. 7000/-
b) From the existing table, add the employees with the basic salary greater than or equal to 7000/-
c) Alter the table to add a net pay column.
d) Replace net pay with 1.5* Basic.
e) Try to remove the net net pay column.
[ It may require no. of steps]
*/
-- a
CREATE TABLE FILTEREDEMPLOYEE AS
SELECT EMPLOYEE.EMP_CODE, EMPLOYEE.EMP_NAME, DEPARTMENT.DEPT_NAME, EMPLOYEE.BASIC
FROM EMPLOYEE, DEPARTMENT
WHERE EMPLOYEE.DEPT_CODE = DEPARTMENT.DEPT_CODE
AND DEPARTMENT.DEPT_CODE = 'D001'
AND EMPLOYEE.BASIC = 7000;

select * from FILTEREDEMPLOYEE;

MariaDB [assignment_3]> SELECT * FROM FILTEREDEMPLOYEE;
+----------+------------+-----------+-------+
| EMP_CODE | EMP_NAME   | DEPT_NAME | BASIC |
+----------+------------+-----------+-------+
| E0011    | Jane Smith | Sales     |  7000 |
+----------+------------+-----------+-------+

-- b
INSERT INTO FilteredEmployee (EMP_CODE, EMP_NAME, DEPT_NAME, BASIC)
SELECT EMPLOYEE.EMP_CODE, EMPLOYEE.EMP_NAME, DEPARTMENT.DEPT_NAME, EMPLOYEE.BASIC
FROM EMPLOYEE, DEPARTMENT
WHERE EMPLOYEE.DEPT_CODE = DEPARTMENT.DEPT_CODE AND BASIC >= 7000;

MariaDB [assignment_3]> SELECT * FROM FILTEREDEMPLOYEE;
+----------+-----------------+-----------+-------+
| EMP_CODE | EMP_NAME        | DEPT_NAME | BASIC |
+----------+-----------------+-----------+-------+
| E0011    | Jane Smith      | Sales     |  7000 |
| E0011    | Jane Smith      | Sales     |  7000 |
| E0012    | Michael Johnson | Marketing |  8000 |
| E0014    | David Wilson    | Finance   |  9000 |
+----------+-----------------+-----------+-------+

-- c
ALTER TABLE FilteredEmployee
ADD COLUMN NET_PAY INTEGER;

MariaDB [assignment_3]> SELECT * FROM FILTEREDEMPLOYEE;
+----------+-----------------+-----------+-------+---------+
| EMP_CODE | EMP_NAME        | DEPT_NAME | BASIC | NET_PAY |
+----------+-----------------+-----------+-------+---------+
| E0011    | Jane Smith      | Sales     |  7000 |    NULL |
| E0011    | Jane Smith      | Sales     |  7000 |    NULL |
| E0012    | Michael Johnson | Marketing |  8000 |    NULL |
| E0014    | David Wilson    | Finance   |  9000 |    NULL |
+----------+-----------------+-----------+-------+---------+

-- d
UPDATE FilteredEmployee
SET NET_PAY = 1.5 * BASIC;

MariaDB [assignment_3]> SELECT * FROM FILTEREDEMPLOYEE;
+----------+-----------------+-----------+-------+---------+
| EMP_CODE | EMP_NAME        | DEPT_NAME | BASIC | NET_PAY |
+----------+-----------------+-----------+-------+---------+
| E0011    | Jane Smith      | Sales     |  7000 |   10500 |
| E0011    | Jane Smith      | Sales     |  7000 |   10500 |
| E0012    | Michael Johnson | Marketing |  8000 |   12000 |
| E0014    | David Wilson    | Finance   |  9000 |   13500 |
+----------+-----------------+-----------+-------+---------+


-- e
ALTER TABLE FilteredEmployee
DROP COLUMN NET_PAY;

MariaDB [assignment_3]> SELECT * FROM FILTEREDEMPLOYEE;
+----------+-----------------+-----------+-------+
| EMP_CODE | EMP_NAME        | DEPT_NAME | BASIC |
+----------+-----------------+-----------+-------+
| E0011    | Jane Smith      | Sales     |  7000 |
| E0011    | Jane Smith      | Sales     |  7000 |
| E0012    | Michael Johnson | Marketing |  8000 |
| E0014    | David Wilson    | Finance   |  9000 |
+----------+-----------------+-----------+-------+

/*6. Drop all the tables that you have created .*/

DROP TABLE FilteredEmployee;
DROP TABLE LEAVE_RECORD;
DROP TABLE EMPLOYEE;
DROP TABLE DEPARTMENT;










