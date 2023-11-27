#pragma once 
#include "first.h"
#include <time.h> 
#include <fstream>

void Test1() {
	size_t num_edges = 0;
	//size_t num_vers = 1;
	size_t step = 100;
	size_t sumTime = 0;
	Graph a;
	ofstream file1("C:/Users/stm_0/source/repos/MSN_Lab/MSN_Lab/cmake/test_1.1(2).txt");
	for (size_t num_vers = 1; num_vers <= 10000; num_vers += step) {
		num_edges = num_vers * num_vers / 10;
		a = Graph(num_vers, num_edges, 1000000);

        clock_t start_time = clock();
		a.Kraskal();
        clock_t end_time = clock();

        double seconds_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		file1 << seconds_time << endl;
        //sumTime += seconds_time;
	}
	file1.close();
	//cout << sumTime << "seconds;\n";
	//sumTime = 0;
	ofstream file2("C:/Users/stm_0/source/repos/MSN_Lab/MSN_Lab/cmake/test_1.2(2).txt");
	for (size_t num_vers = 1; num_vers <= 10000; num_vers += step) {
		num_edges = num_vers * num_vers;
		a = Graph(num_vers, num_edges, 1000000);

		clock_t start_time = clock();
		a.Kraskal();
		clock_t end_time = clock();

		double seconds_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		file2 << seconds_time << endl;
		//sumTime += seconds_time;
	}
	file2.close();
	//cout << sumTime << "seconds;\n";
}

void Test2() {
	size_t num_edges = 0;
	//size_t num_vers = 1;
	size_t step = 100;
	size_t sumTime = 0;
	Graph a;
	ofstream file1("C:/Users/stm_0/source/repos/MSN_Lab/MSN_Lab/cmake/test_2.1(2).txt");
	for (size_t num_vers = 101; num_vers <= 10000; num_vers += step) {
		num_edges = num_vers * 100;
		a = Graph(num_vers, num_edges, 1000000);

		clock_t start_time = clock();
		a.Kraskal();
		clock_t end_time = clock();

		double seconds_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		file1 << seconds_time << endl;
		//sumTime += seconds_time;
	}
	file1.close();
	//cout << sumTime << "seconds;\n";
	//sumTime = 0;
	ofstream file2("C:/Users/stm_0/source/repos/MSN_Lab/MSN_Lab/cmake/test_2.2(2).txt");
	for (size_t num_vers = 101; num_vers <= 10000; num_vers += step) {
		num_edges = num_vers * 1000;
		a = Graph(num_vers, num_edges, 1000000);

		clock_t start_time = clock();
		a.Kraskal();
		clock_t end_time = clock();

		double seconds_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		file2 << seconds_time << endl;
		//sumTime += seconds_time;
	}
	file2.close();
	//cout << sumTime << "seconds;\n";
}

void Test3() {
	//size_t num_edges = 0;
	size_t num_vers = 100000;
	size_t step = 100000;
	size_t sumTime = 0;
	ofstream file("C:/Users/stm_0/source/repos/MSN_Lab/MSN_Lab/cmake/test_3(2).txt");
	for (size_t num_edges = 0; num_edges <= 10000000; num_edges += step) {
		Graph a = Graph(num_vers, num_edges, 1000000);

		clock_t start_time = clock();
		a.Kraskal();
		clock_t end_time = clock();

		double seconds_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		file << seconds_time << endl;
		//sumTime += seconds_time;
	}
	file.close();
	//cout << sumTime << "seconds;\n";
}

void Test4() {
	size_t num_vers = 10000;
	size_t num_edges = num_vers * 1000;
	size_t step = 1;
	size_t sumTime = 0;
	Graph a;
	ofstream file1("C:/Users/stm_0/source/repos/MSN_Lab/MSN_Lab/cmake/test_4.1(2).txt");
	for (int i = 1; i < 200; i++) {
		a = Graph(num_vers, num_edges, 10000 + i);

		clock_t start_time = clock();
		a.Kraskal();
		clock_t end_time = clock();

		double seconds_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		file1 << seconds_time << endl;
	}
	file1.close();
	
	//sumTime += seconds_time * 200;
	//cout << sumTime << " seconds;\n";


	////sumTime = 0;
	////num_edges = num_vers * 1000;
	//ofstream file2("C:/Users/stm_0/source/repos/MSN_Lab/MSN_Lab/cmake/test_4.2.txt");
	//start_time = clock();

	//a = Graph(num_vers, num_edges, 10000);
	//a.Kraskal();

	//end_time = clock();
	//seconds_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	//file1 << seconds_time << endl;
	//file1.close();
	////sumTime += seconds_time * 200;

	////cout << sumTime << " seconds;\n";
}