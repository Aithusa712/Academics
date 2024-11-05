DROP TABLE Fact_Sales;
DROP TABLE Dim_Date;
DROP TABLE Dim_Supplier;
DROP TABLE Dim_Employee;
DROP TABLE Dim_Product;
DROP TABLE Dim_Customer;


-- Create the dimension tables
CREATE TABLE Dim_Customer (
    Customer_ID NUMBER PRIMARY KEY,
    FirstName VARCHAR2(50) NOT NULL,
    LastName VARCHAR2(50) NOT NULL,
    State VARCHAR2(50) NOT NULL
);

CREATE TABLE Dim_Product (
    Product_ID NUMBER PRIMARY KEY,
    ProductName VARCHAR2(50) NOT NULL,
    Category VARCHAR2(50) NOT NULL
);

CREATE TABLE Dim_Employee (
    Employee_ID NUMBER PRIMARY KEY,
    Employee_Name VARCHAR2(50) NOT NULL,
    BranchID NUMBER NOT NULL
);

CREATE TABLE Dim_Supplier (
    Supplier_ID VARCHAR2(50) PRIMARY KEY,
    Name VARCHAR2(50) NOT NULL,
    Country VARCHAR2(50) NOT NULL
);

CREATE TABLE Dim_Date (
    Date_ID NUMBER PRIMARY KEY,
    SalesDate DATE NOT NULL
);

-- Create the fact table
CREATE TABLE Fact_Sales (
    Sales_ID NUMBER PRIMARY KEY,
    Product_ID NUMBER NOT NULL,
    Customer_ID NUMBER NOT NULL,
    Employee_ID NUMBER NOT NULL,
    Supplier_ID VARCHAR2(50) NOT NULL,
    Date_ID NUMBER NOT NULL,
    Repeat_Purchases NUMBER NOT NULL, --0 or 1 only 0 for false 1 for true --
    Unitprice NUMBER NOT NULL,
    Quantity NUMBER NOT NULL,
    Total_Sales_Per_Category NUMBER NOT NULL,
    Total_Sales_Per_Customer NUMBER NOT NULL,
    Total_Sales_Per_Employee NUMBER NOT NULL,
    Total_Sales_Per_Supplier NUMBER NOT NULL,
    CONSTRAINT FK_Sales_Product FOREIGN KEY (Product_ID) REFERENCES Dim_Product(Product_ID),
    CONSTRAINT FK_Sales_Customer FOREIGN KEY (Customer_ID) REFERENCES Dim_Customer(Customer_ID),
    CONSTRAINT FK_Sales_Employee FOREIGN KEY (Employee_ID) REFERENCES Dim_Employee(Employee_ID),
    CONSTRAINT FK_Sales_Supplier FOREIGN KEY (Supplier_ID) REFERENCES Dim_Supplier(Supplier_ID),
    CONSTRAINT FK_Sales_Date FOREIGN KEY (Date_ID) REFERENCES Dim_Date(Date_ID)
);


    -- Insert into Dim_Employee
INSERT ALL
  INTO Dim_Employee (Employee_ID, Employee_Name, BranchID) VALUES (380, 'Basher Bigmouth', 1)
  INTO Dim_Employee (Employee_ID, Employee_Name, BranchID) VALUES (381, 'Chagall Mark', 1)
  INTO Dim_Employee (Employee_ID, Employee_Name, BranchID) VALUES (382, 'Graves Morris', 2)
  INTO Dim_Employee (Employee_ID, Employee_Name, BranchID) VALUES (383, 'Hoiriuschi Paul', 3)
  INTO Dim_Employee (Employee_ID, Employee_Name, BranchID) VALUES (384, 'Julio Bloxham Smith', 3)
  INTO Dim_Employee (Employee_ID, Employee_Name, BranchID) VALUES (385, 'Kandinsky Wassily', 3)
  INTO Dim_Employee (Employee_ID, Employee_Name, BranchID) VALUES (386, 'Klee Paul', 2)
  INTO Dim_Employee (Employee_ID, Employee_Name, BranchID) VALUES (387, 'Matisse Henri', 1)
  INTO Dim_Employee (Employee_ID, Employee_Name, BranchID) VALUES (388, 'Miro Joanne', 2)
  INTO Dim_Employee (Employee_ID, Employee_Name, BranchID) VALUES (389, 'Sargent John Singer', 2)
  INTO Dim_Employee (Employee_ID, Employee_Name, BranchID) VALUES (390, 'Tobey James', 3)
SELECT * FROM dual;

-- Insert into Dim_Supplier
INSERT ALL
  INTO Dim_Supplier (Supplier_ID, Name, Country) VALUES ('J454', 'Dogs R Us', 'Australia')
  INTO Dim_Supplier (Supplier_ID, Name, Country) VALUES ('J569', 'Massive Dogs', 'Brazil')
  INTO Dim_Supplier (Supplier_ID, Name, Country) VALUES ('J741', 'Makin Dogs Taste Good', 'New Zealand')
  INTO Dim_Supplier (Supplier_ID, Name, Country) VALUES ('J639', 'Keepum Tidy', 'Australia')
SELECT * FROM dual;

-- Insert into Dim_Customer
INSERT ALL
  INTO Dim_Customer (Customer_ID, FirstName, LastName, State) VALUES (1, 'Barkley', 'Barker', 'California')
  INTO Dim_Customer (Customer_ID, FirstName, LastName, State) VALUES (2, 'Whiskers', 'Wags', 'Texas')
  INTO Dim_Customer (Customer_ID, FirstName, LastName, State) VALUES (3, 'Buddy', 'Bones', 'New York')
SELECT * FROM dual;

-- Insert into Dim_Product
INSERT ALL
  INTO Dim_Product (Product_ID, ProductName, Category) VALUES (101, 'Dog Food Premium', 'Pet Supplies')
  INTO Dim_Product (Product_ID, ProductName, Category) VALUES (102, 'Dog Collar Leather', 'Pet Accessories')
  INTO Dim_Product (Product_ID, ProductName, Category) VALUES (103, 'Dog Toy Squeaky', 'Pet Toys')
SELECT * FROM dual;

-- Insert into Dim_Date
INSERT ALL
  INTO Dim_Date (Date_ID, SalesDate) VALUES (1001, TO_DATE('2024-10-01', 'YYYY-MM-DD'))
  INTO Dim_Date (Date_ID, SalesDate) VALUES (1002, TO_DATE('2024-11-02', 'YYYY-MM-DD'))
  INTO Dim_Date (Date_ID, SalesDate) VALUES (1003, TO_DATE('2023-12-03', 'YYYY-MM-DD'))
  INTO Dim_Date (Date_ID, SalesDate) VALUES (1004, TO_DATE('2024-09-04', 'YYYY-MM-DD'))
SELECT * FROM dual;

-- Insert into Fact_Sales
INSERT ALL
  INTO Fact_Sales (Sales_ID, Product_ID, Customer_ID, Employee_ID, Supplier_ID, Date_ID, Repeat_Purchases, Unitprice, Quantity, Total_Sales_Per_Category, Total_Sales_Per_Customer, Total_Sales_Per_Employee, Total_Sales_Per_Supplier)
      VALUES (1, 101, 1, 380, 'J454', 1001, 0, 39, 2, 79, 79, 79, 79)
  INTO Fact_Sales (Sales_ID, Product_ID, Customer_ID, Employee_ID, Supplier_ID, Date_ID, Repeat_Purchases, Unitprice, Quantity, Total_Sales_Per_Category, Total_Sales_Per_Customer, Total_Sales_Per_Employee, Total_Sales_Per_Supplier)
      VALUES (2, 102, 2, 381, 'J569', 1002, 1, 19, 3, 59, 59, 59, 59)
  INTO Fact_Sales (Sales_ID, Product_ID, Customer_ID, Employee_ID, Supplier_ID, Date_ID, Repeat_Purchases, Unitprice, Quantity, Total_Sales_Per_Category, Total_Sales_Per_Customer, Total_Sales_Per_Employee, Total_Sales_Per_Supplier)
      VALUES (3, 103, 3, 382, 'J741', 1003, 0, 9, 5, 49, 49, 49, 49)
  INTO Fact_Sales (Sales_ID, Product_ID, Customer_ID, Employee_ID, Supplier_ID, Date_ID, Repeat_Purchases, Unitprice, Quantity, Total_Sales_Per_Category, Total_Sales_Per_Customer, Total_Sales_Per_Employee, Total_Sales_Per_Supplier)
      VALUES (4, 101, 1, 383, 'J639', 1004, 1, 39, 1, 39, 39, 39, 39)
SELECT * FROM dual;


COMMIT;
