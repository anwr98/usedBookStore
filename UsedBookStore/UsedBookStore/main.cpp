
#include <iostream>
#include <string>
#include <mysql.h>
#include <conio.h>

using namespace std;

MYSQL* conn;
int qstate;

void printMenue();
MYSQL_RES* runQuery(string query);
void showRes(MYSQL_RES* res);
void searchBook();
void oldestCustomer();
void oldestBook();
void showOrders();
void countBook();
void mostAutherReaded();
void mostThreeCustomers();
void mostTranslatedBook();
void customerBookDealsHistory();
void customeOrdersHistory();
void customersHaveSeparateDelivery();
void getDeliveryStatus();
void getXpressCosts();
void getBitRevenues();
void dealsUpAVGYears();
void deliveryXpressPostBefoureYear();
void deliveryHaveTwoReleasSameBook();
void customersDidNotBuy2Years();
void customersDidNotAnswer2Weeks();
void monthlyBooksCounting();
void pruchasesBetweenTowDays();
void monthProfitsStore();
void avrageYearsViaMonthlySum();
void monthSalaryForEmployee();
void bestEmployeeOfMonth();

int main()
{
	bool flag = true;
	int choice = 0;
	string x;

	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "used_books_store", 3306, NULL, 0);
	if (conn)
		cout << "connection to database saccess, database is ready" << endl << endl;
	else
		cout << "connection to database faild." << endl;

	system("pause");

	while (choice != 99)
	{

		system("CLS");
		printMenue();

		cout << endl << "Enter choice number:";
		cin >> choice;

		system("CLS");
		switch (choice)
		{
		case 1:
			searchBook();
			break;

		case 2:
			oldestCustomer();
			break;

		case 3:
			oldestBook();
			break;

		case 4:
			showOrders();
			break;

		case 5:
			countBook();
			break;

		case 6:
			mostAutherReaded();
			break;

		case 7:
			mostThreeCustomers();
			break;

		case 8:
			mostTranslatedBook();
			break;

		case 9:
			customerBookDealsHistory();
			break;

		case 10:
			customeOrdersHistory();
			break;

		case 12:
			customersHaveSeparateDelivery();
			break;

		case 13:
			getDeliveryStatus();
			break;

		case 14:
			getXpressCosts();
			break;

		case 15:
			getBitRevenues();
			break;

		case 16:
			dealsUpAVGYears();
			break;

		case 17:
			deliveryXpressPostBefoureYear();
			break;

		case 18:
			deliveryHaveTwoReleasSameBook();
			break;

		case 19:
			customersDidNotBuy2Years();
			break;

		case 20:
			customersDidNotAnswer2Weeks();
			break;

		case 21:
			monthlyBooksCounting();
			break;

		case 22:
			pruchasesBetweenTowDays();
			break;

		case 23:
			monthProfitsStore();
			break;

		case 24:
			avrageYearsViaMonthlySum();
			break;

		case 25:
			monthSalaryForEmployee();
			break;

		case 26:
			bestEmployeeOfMonth();
			break;

		case 99:
			cout << "good bye - book store :)" << endl;
			break;

		default:
			cout << "wrong choice!" << endl;
			system("pause");
			break;
		}

	}


}

void printMenue()
{
	system("CLS");
	cout << "choose number choice please:" << endl;
	cout << "1.search book\t\t\t\t"<< 
		"14.show xpress delivery costs for month" << endl;
	cout << "2.oldest customer\t\t\t" <<
		"15.show Bit revenues for month" << endl;
	cout << "3.oldest book\t\t\t\t" <<
		"16.show deals up avrage las 12 month" << endl;
	cout << "4.get orders\t\t\t\t" <<
		"17.show post an xpress number at last 12 month" << endl;
	cout << "5.show book deals\t\t\t" <<
		"18.show delivries have two releas from the same book" << endl;
	cout << "6.most popular author between two dates\t" <<
		"19.show customers did not buy for two years" << endl;
	cout << "7.most three customer buy books\t\t" <<
		"20.show customers did not answer calling more one two weeks" << endl;
	cout << "8.most translated book\t\t\t" <<
		"21.monthly books counting list" << endl;
	cout << "9.customer history deals\t\t" <<
		"22.book store pruchases between two months" << endl;
	cout << "10.customer orders history\t\t" <<
		"23.store profits at month in year" << endl;
	cout << "11.calculate delivery price\t\t" <<
		"24.store deals avrage by years" << endl;
	cout << "12.customers delase separate delivery\t" <<
		"25.employee salary" << endl;
	cout << "13.get delivery status\t\t\t" <<
		"26.best employee of month" << endl;
	cout << endl << "\t\t\t\t99.EXIT" << endl;
}

MYSQL_RES* runQuery(string query)
{
	MYSQL_RES* res;
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);

	if (!qstate)
	{
		return mysql_store_result(conn);
	}
	else
	{
		cout << "Queryt failed: " << mysql_error(conn) << endl;
		return NULL;
	}
}

void showRes(MYSQL_RES* res)
{
	MYSQL_FIELD* field;
	MYSQL_ROW row;
	int rowCount = 0;

	while (field = mysql_fetch_field(res))
	{
		cout << field->name << "\t";
		rowCount++;
	}

	cout << endl;
	cout << string(50, '-') << endl;
	try {
		while (row = mysql_fetch_row(res))
		{
			for (int i = 0; i < rowCount; i++)
			{
				cout << (row[i] == NULL? "\t": row[i]) << "\t";
			}
			cout << endl;

		}
	}
	catch (const exception& e) { }

	cout << string(50, '-') << endl;
	cout << endl;
}

//1
void searchBook()
{
	string str;

	cout << "Enter book title or auther name: ";
	cin >> str;

	string query = 
		"SELECT * FROM books "
		"WHERE title = '" + str + "' " 
		"OR auther_name like '%" + str + "%'";
	
	cout << query << endl;

	showRes(runQuery(query));

	system("pause");
}

//2
void oldestCustomer()
{
	string query =
		"SELECT * FROM `customers` ORDER BY created_at LIMIT 1";
	cout << query << endl;

	showRes(runQuery(query));
	system("pause");
}

//3
void oldestBook()
{
	string query =
		"SELECT * FROM `books` ORDER BY created_at LIMIT 1";
	cout << query << endl;

	showRes(runQuery(query));
	system("pause");
}

//4
void showOrders()
{
	string query =
		"SELECT * FROM orders WHERE status = 'binding'  ORDER BY created_at";
	cout << query << endl;
	showRes(runQuery(query));
	system("pause");
}

//5
void countBook()
{
	string str;

	cout << "Enter book title or auther name: ";
	cin >> str;

	string query =
		"SELECT books.id, books.title, books.auther_name, "
		"books.translator_name, books.release_name, books.release_year, "
		"books.condition, COUNT(deals_details.id) AS 'counts' "
		"FROM deals_details "
		"JOIN books ON deals_details.book_id = books.id "
		"WHERE books.title = '"+ str +"' "
		"OR books.auther_name like '%" + str + "%' "
		"GROUP BY books.id, books.title, books.auther_name, "
		"books.translator_name, books.release_name, books.release_year, books.condition";

	showRes(runQuery(query));

	system("pause");
}

//6
void mostAutherReaded()
{
	string date1,date2;

	cout << "Enter start date: ";
	cin >> date1;

	cout << "Enter last date: ";
	cin >> date2;

	string query =
		"SELECT books.auther_name,COUNT(books.id) "
		"FROM deals_details "
		"JOIN books ON deals_details.book_id = books.id "
		"JOIN deals ON deals_details.deal_id = deals.id "
		"WHERE deals.s_date BETWEEN '"+ date1 +"' AND '" + date1 + "' "
		"GROUP BY books.auther_name "
		"ORDER BY COUNT(books.id) "
		"LIMIT 1";

	showRes(runQuery(query));

	system("pause");
}

//7
void mostThreeCustomers() 
{
	string query =
		"SELECT customers.*, COUNT(deals_details.id) as 'reads' "
		"FROM deals_details "
		"JOIN deals ON deals_details.deal_id = deals.id "
		"JOIN customers ON deals.customer_id = customers.id "
		"GROUP BY customers.id, customers.fname, customers.lname, "
		"customers.address, customers.phone_number, customers.created_at "
		"ORDER BY COUNT(deals_details.id) DESC "
		"LIMIT 3";

	showRes(runQuery(query));

	system("pause");
}

//8
void mostTranslatedBook()
{
	string query =
		"SELECT books_translated.title, COUNT(books_translated.title) "
		"FROM("
		"	SELECT books.title, books.translator_name "
		"	FROM books "
		"	GROUP BY books.title, books.translator_name) AS books_translated "
		"GROUP BY books_translated.title "
		"ORDER BY COUNT(books_translated.title) DESC "
		"LIMIT 1";

	showRes(runQuery(query));
	system("pause");
}

//9
void customerBookDealsHistory()
{
	string str;

	cout << "Enter customer name or another info: ";
	cin >> str;

	string query =
		"SELECT * "
		"FROM Customers "
		"WHERE cast(id AS CHAR) = '"+ str +"' "
		"OR fname LIKE '%" + str + "%' "
		"OR lname LIKE '%" + str + "%'"
		"OR phone_number LIKE '%" + str + "%'";

	showRes(runQuery(query));
	cout << "choose one of the customers by id: ";
	cin >> str;

	query =
		"SELECT books.*,deals_details.price ,deals.s_date "
		"FROM deals_details "
		"JOIN deals ON deals_details.deal_id = deals.id "
		"JOIN books ON deals_details.book_id = books.id "
		"WHERE cast(deals.customer_id AS CHAR) = '" + str + "' "
		"ORDER BY deals.s_date";

	showRes(runQuery(query));

	system("pause");
}

//10
void customeOrdersHistory()
{
	string str;

	cout << "Enter customer name or another info: ";
	cin >> str;

	string query =
		"SELECT * "
		"FROM Customers "
		"WHERE cast(id AS CHAR) = '" + str + "' "
		"OR fname LIKE '%" + str + "%' "
		"OR lname LIKE '%" + str + "%'"
		"OR phone_number LIKE '%" + str + "%'";

	showRes(runQuery(query));
	cout << "choose one of the customers by id: ";
	cin >> str;

	query =
		"SELECT books.id,books.title,books.translator_name, orders.created_at,  "
		"IF(books.id IN(SELECT purchase.book_id FROM purchase), 'yes', 'no') AS 'in_inventory', "
		"IF(books.id IN(SELECT deals_details.book_id FROM deals_details JOIN deals ON deals_details.deal_id = deals.id WHERE deals.customer_id = " + str +"), 'yes', 'no') AS 'deal' "
		"FROM books "
		"JOIN orders ON orders.book_id = books.id "
		"WHERE orders.customer_id = " + str ;

	showRes(runQuery(query));
	system("pause");
}

//12
void customersHaveSeparateDelivery()
{
	string query =
		"SELECT customers.id, CONCAT(customers.fname,' ',customers.lname) AS name,deliveries.* "
		"FROM customers "
		"JOIN deals ON deals.customer_id = customers.id "
		"JOIN deals_details ON deals_details.deal_id = deals.id "
		"JOIN deliveries_details ON deliveries_details.deal_details_id = deals_details.id "
		"JOIN deliveries ON deliveries_details.delivery_id = deliveries.id "
		"WHERE deals.id IN( "
		"	SELECT deals.id "
		"	FROM customers "
		"	JOIN deals ON deals.customer_id = customers.id "
		"	JOIN deals_details ON deals_details.deal_id = deals.id "
		"	JOIN deliveries_details ON deliveries_details.deal_details_id = deals_details.id "
		"	GROUP BY customers.id, CONCAT(customers.fname, ' ', customers.lname), deals.id "
		"	HAVING COUNT(deliveries_details.id) >= 2)";

	showRes(runQuery(query));
	system("pause");
}

//13
void getDeliveryStatus()
{
	string str;

	cout << "Enter customer name or another info: ";
	cin >> str;

	string query =
		"SELECT * "
		"FROM Customers "
		"WHERE cast(id AS CHAR) = '" + str + "' "
		"OR fname LIKE '%" + str + "%' "
		"OR lname LIKE '%" + str + "%'"
		"OR phone_number LIKE '%" + str + "%'";

	showRes(runQuery(query));
	cout << "choose one of the customers by id: ";
	cin >> str;

	query =
		"SELECT deliveries.* "
		"FROM deals "
		"JOIN deals_details ON deals_details.deal_id = deals.id "
		"JOIN deliveries_details ON deliveries_details.deal_details_id = deals_details.id "
		"JOIN deliveries ON deliveries_details.delivery_id = deliveries.id "
		"WHERE deals.customer_id = " + str;

	showRes(runQuery(query));


	cout << "choose one of the delivery by id: ";
	cin >> str;

	query = "SELECT * FROM deliveries WHERE id = " + str;
	MYSQL_RES* rs = runQuery(query);
	MYSQL_ROW row;

	if (row = mysql_fetch_row(rs))
	{
		cout << " the status of delivery with id " << row[0] << " is " << row[5] << endl;
	}

	system("pause");
}

//14
void getXpressCosts()
{
	string str;

	cout << "Enter month number: ";
	cin >> str;

	string query =
		"SELECT COALESCE(SUM(deliveries.price),0) "
		"FROM deliveries "
		"WHERE deliveries.type = 'xpress' "
		"AND MONTH(deliveries.s_date) = " + str;

	MYSQL_RES* rs = runQuery(query);
	MYSQL_ROW row;
	if (row = mysql_fetch_row(rs))
	{
		cout << "the xpress cost deliveries of month " << str << " is " << row[0] << endl;
	}

	system("pause");
}

//15
void getBitRevenues()
{
	string str;

	cout << "Enter month number: ";
	cin >> str;

	string query =
		"SELECT COALESCE(SUM(deals_details.price),0) "
		"FROM deals "
		"JOIN deals_details ON deals_details.deal_id = deals.id "
		"WHERE deals.purchase_type = 'Bit' "
		"AND MONTH(deals.s_date) = " + str;

	MYSQL_RES* rs = runQuery(query);
	MYSQL_ROW row;
	
	if (row = mysql_fetch_row(rs))
	{
		cout << "the bit revenues of month " << str << " is " << row[0] << endl;
	}

	system("pause");
}

//16
void dealsUpAVGYears()
{
	string query =
		"SELECT deals.id, SUM(deals_details.price) as avrage "
		"FROM deals JOIN deals_details ON deals_details.deal_id = deals.id "
		"WHERE deals.s_date >= DATE_SUB(NOW(), INTERVAL 1 YEAR) "
		"GROUP BY deals.id "
		"HAVING avrage > ( "
		"	SELECT AVG(sum_deals.avrage) "
		"	FROM( "
		"		SELECT deals.id, SUM(deals_details.price) as avrage "
		"		FROM deals JOIN deals_details ON deals_details.deal_id = deals.id "
		"		WHERE deals.s_date >= DATE_SUB(NOW(), INTERVAL 1 YEAR) "
		"		GROUP BY deals.id) AS sum_deals)";

	showRes(runQuery(query));
	system("pause");
}

//17
void deliveryXpressPostBefoureYear()
{
	string query =
		"SELECT deliveries.type, COUNT(deliveries.id) "
		"FROM deliveries "
		"WHERE deliveries.s_date >= DATE_SUB(NOW(), INTERVAL 1 YEAR) "
		"AND(deliveries.type = 'xpress' OR deliveries.type = 'post') "
		"GROUP BY deliveries.type";

	showRes(runQuery(query));
	system("pause");
}

//18
void deliveryHaveTwoReleasSameBook()
{
	string query =
		"SELECT deliveries_details.delivery_id, books.title, COUNT(books.id) AS releases_number "
		"FROM deliveries_details "
		"JOIN deals_details ON deals_details.id = deliveries_details.delivery_id "
		"JOIN books ON books.id = deals_details.book_id "
		"GROUP BY deliveries_details.delivery_id, books.title, books.release_name "
		"HAVING COUNT(books.id) >= 2";

	showRes(runQuery(query));
	system("pause");
}

//19
void customersDidNotBuy2Years()
{
	string query =
		"SELECT DISTINCT customers.* "
		"FROM customers "
		"JOIN deals ON deals.customer_id = customers.id "
		"WHERE customers.id "
		"AND deals.s_date < DATE_SUB(NOW(), INTERVAL 2 YEAR)";

	showRes(runQuery(query));
	system("pause");
}


//20
void customersDidNotAnswer2Weeks()
{
	string query =
		"SELECT DISTINCT customers.* "
		"FROM customers "
		"JOIN orders ON orders.customer_id = customers.id "
		"AND orders.calling_date < DATE_SUB(NOW(), INTERVAL 2 WEEK)";

	showRes(runQuery(query));
	system("pause");
}

//21
void monthlyBooksCounting()
{
	string query =
		"SELECT DISTINCT YEAR(purchase.p_date) AS a_year, MONTH(purchase.p_date) AS a_month, "
		"	(SELECT SUM(purchase.quantity) "
		"	FROM purchase "
		"	WHERE YEAR(purchase.p_date) <= a_year AND MONTH(purchase.p_date) <= a_month) - "
		"	(SELECT COUNT(deals_details.id) "
		"	FROM deals_details JOIN deals ON deals_details.deal_id = deals.id "
		"	WHERE YEAR(deals.s_date) <= a_year AND MONTH(deals.s_date) <= a_month) AS books_count "
		"FROM purchase";

	showRes(runQuery(query));
	system("pause");
}

//22
void pruchasesBetweenTowDays()
{
	string date1, date2;
	cout << "Enter first date: ";
	cin >> date1;

	cout << "Enter last date: ";
	cin >> date2;

	string query =
		"SELECT SUM(purchase.quantity), SUM(purchase.quantity*purchase.price) "
		"FROM purchase "
		"WHERE purchase.p_date BETWEEN '" + date1 + "' AND '" + date2 + "'";

	showRes(runQuery(query));
	system("pause");
}

//23
void monthProfitsStore()
{
	string month, year;
	cout << "Enter month: ";
	cin >> month;

	cout << "Enter year: ";
	cin >> year;

	string query =
		"SELECT COALESCE("
		"(SELECT SUM(purchase.price * purchase.quantity) "
		"	FROM purchase "
		"	WHERE MONTH(purchase.p_date) = "+month+" AND YEAR(purchase.p_date) = "+ year +") "
		"- "
		"(SELECT SUM(deals_details.price) "
		"	FROM deals_details "
		"	JOIN deals ON deals.id = deals_details.deal_id "
		"	WHERE MONTH(deals.s_date) = " + month + " AND YEAR(deals.s_date) = " + year + "),0) AS store_pro";

	showRes(runQuery(query));
	system("pause");
}

//24
void avrageYearsViaMonthlySum()
{
	string query =
		"SELECT monthly_sum.a_year, AVG(monthly_sum.a_sum) "
		"FROM "
		"(SELECT MONTH(deals.s_date) AS a_month, YEAR(deals.s_date) AS a_year, SUM(deals_details.price) AS a_sum "
		"	FROM deals "
		"	JOIN deals_details ON deals.id = deals_details.deal_id "
		"	GROUP BY MONTH(deals.s_date), YEAR(deals.s_date)) AS monthly_sum "
		"GROUP BY monthly_sum.a_year";

	showRes(runQuery(query));
	system("pause");
}

//25
void monthSalaryForEmployee()
{
	string id, month, year;
	cout << "Enter employee id: ";
	cin >> id;

	cout << "Enter month: ";
	cin >> month;

	cout << "Enter year: ";
	cin >> year;

	string query =
		"SELECT COALESCE(SUM(working_hours.quantity * employees.hour_price),0) AS salary "
		"FROM employees "
		"JOIN working_hours ON working_hours.worker_id = employees.id "
		"WHERE working_hours.w_month = "+ month +" AND working_hours.w_year = "+ year +"  AND employees.id = '"+ id +"'";

	showRes(runQuery(query));
	system("pause");
}

//26
void bestEmployeeOfMonth()
{
	string month, year;

	cout << "Enter month: ";
	cin >> month;

	cout << "Enter year: ";
	cin >> year;

	string query =
		"SELECT employees.id, employees.fname, employees.lname "
		"FROM employees "
		"JOIN deals ON deals.employee_id = employees.id "
		"WHERE MONTH(deals.s_date) = " + month + " "
		"AND YEAR(deals.s_date) = " + month + " "
		"ORDER BY COUNT(deals.id) DESC "
		"LIMIT 1";

	showRes(runQuery(query));
	system("pause");
}