#include <iostream>
#include <string>

struct SalesData {
	std::string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0.0;
};

int main() {
	SalesData data1, data2;
	double price = 0;

	std::cout << "BookNo UnitsSold Price" << std::endl;
	std::cin >> data1.bookNo >> data1.unitsSold >> price;
	data1.revenue = data1.unitsSold * price;
	std::cout << "BookNo UnitsSold Price" << std::endl;
	std::cin >> data2.bookNo >> data2.unitsSold >> price;
	data2.revenue = data2.unitsSold * price;

	if (data1.bookNo == data2.bookNo) {
		unsigned totalCnt = data1.unitsSold + data2.unitsSold;
		double totalRevenue = data1.revenue + data2.revenue;
		std::cout << data1.bookNo << " " << totalCnt << " "
			  << totalRevenue << " ";
		if (totalCnt != 0) {
			std::cout << totalRevenue / totalCnt << std::endl;
		} else
			std::cout << "(no sales)" << std::endl;
		return 0;
	} else {
		std::cerr << "Data must refer to the same ISBN" << std::endl;
		return -1;
	}
}
