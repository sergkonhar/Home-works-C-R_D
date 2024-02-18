#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <algorithm>
#include <string>

std::mutex threadMutex;

std::vector<int> generateVector(int size);
void sumElements(std::vector<int> inVector, int startIndex, int endIndex, int& sumResult);

int main()
{
	std::vector<int> vector10000 = generateVector(10000);
	std::vector<int> vector100000 = generateVector(100000);
	std::vector<int> vector1000000 = generateVector(1000000);
	std::vector<int> vector10000000 = generateVector(10000000);
	std::vector<int> vector100000000 = generateVector(100000000);

	int resultOfSum =0;

	std::cout << std::endl;
	std::cout << "PC Threads: " << std::thread::hardware_concurrency();
	std::cout << std::endl;
	std::cout << "PC Threads 2X: " << std::thread::hardware_concurrency()*2;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Single Thread";
	std::cout << std::endl;

	auto begin = std::chrono::high_resolution_clock::now();

	std::thread tread1(sumElements, vector10000, 0, 9999, std::ref(resultOfSum));
	tread1.join();

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 10000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;


	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread2(sumElements, vector100000, 0, 99999, std::ref(resultOfSum));
	tread2.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 100000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;


	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread3(sumElements, vector1000000, 0, 999999, std::ref(resultOfSum));
	tread3.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 1000000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;


	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread4(sumElements, vector10000000, 0, 9999999, std::ref(resultOfSum));
	tread4.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 10000000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;


	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread5(sumElements, vector100000000, 0, 99999999, std::ref(resultOfSum));
	tread5.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 100000000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;

	std::cout << std::endl;
	std::cout << "Two Threads";
	std::cout << std::endl;



	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread6(sumElements, vector10000, 0, 4999, std::ref(resultOfSum));
	std::thread tread7(sumElements, vector10000, 5000, 9999, std::ref(resultOfSum));
	
	tread6.join();
	tread7.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 10000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;

	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread8(sumElements, vector100000, 0, 49999, std::ref(resultOfSum));
	std::thread tread9(sumElements, vector100000, 50000, 99999, std::ref(resultOfSum));

	tread8.join();
	tread9.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 100000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;

	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread10(sumElements, vector1000000, 0, 499999, std::ref(resultOfSum));
	std::thread tread11(sumElements, vector1000000, 500000, 999999, std::ref(resultOfSum));

	tread10.join();
	tread11.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 1000000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;


	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread12(sumElements, vector10000000, 0, 4999999, std::ref(resultOfSum));
	std::thread tread13(sumElements, vector10000000, 5000000, 9999999, std::ref(resultOfSum));

	tread12.join();
	tread13.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 10000000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;


	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread14(sumElements, vector100000000, 0, 49999999, std::ref(resultOfSum));
	std::thread tread15(sumElements, vector100000000, 50000000, 99999999, std::ref(resultOfSum));

	tread14.join();
	tread15.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 100000000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;


	std::cout << std::endl;
	std::cout << "Eigth Threads";
	std::cout << std::endl;

	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread16(sumElements, vector10000, 0, 1249, std::ref(resultOfSum));
	std::thread tread17(sumElements, vector10000, 1250, 2499, std::ref(resultOfSum));
	std::thread tread18(sumElements, vector10000, 2500, 3749, std::ref(resultOfSum));
	std::thread tread19(sumElements, vector10000, 3750, 4999, std::ref(resultOfSum));
	std::thread tread20(sumElements, vector10000, 5000, 6249, std::ref(resultOfSum));
	std::thread tread21(sumElements, vector10000, 6250, 7499, std::ref(resultOfSum));
	std::thread tread22(sumElements, vector10000, 7500, 8749, std::ref(resultOfSum));
	std::thread tread23(sumElements, vector10000, 8750, 9999, std::ref(resultOfSum));

	tread16.join();
	tread17.join();
	tread18.join();
	tread19.join();
	tread20.join();
	tread21.join();
	tread22.join();
	tread23.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 10000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;

	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread24(sumElements, vector100000, 0, 12499, std::ref(resultOfSum));
	std::thread tread25(sumElements, vector100000, 12500, 24999, std::ref(resultOfSum));
	std::thread tread26(sumElements, vector100000, 25000, 37499, std::ref(resultOfSum));
	std::thread tread27(sumElements, vector100000, 37500, 49999, std::ref(resultOfSum));
	std::thread tread28(sumElements, vector100000, 50000, 62499, std::ref(resultOfSum));
	std::thread tread29(sumElements, vector100000, 62500, 74999, std::ref(resultOfSum));
	std::thread tread30(sumElements, vector100000, 75000, 87499, std::ref(resultOfSum));
	std::thread tread31(sumElements, vector100000, 87500, 99999, std::ref(resultOfSum));

	tread24.join();
	tread25.join();
	tread26.join();
	tread27.join();
	tread28.join();
	tread29.join();
	tread30.join();
	tread31.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 100000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;



	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread32(sumElements, vector1000000, 0, 124999, std::ref(resultOfSum));
	std::thread tread33(sumElements, vector1000000, 125000, 249999, std::ref(resultOfSum));
	std::thread tread34(sumElements, vector1000000, 250000, 374999, std::ref(resultOfSum));
	std::thread tread35(sumElements, vector1000000, 375000, 499999, std::ref(resultOfSum));
	std::thread tread36(sumElements, vector1000000, 500000, 624999, std::ref(resultOfSum));
	std::thread tread37(sumElements, vector1000000, 625000, 749999, std::ref(resultOfSum));
	std::thread tread38(sumElements, vector1000000, 750000, 874999, std::ref(resultOfSum));
	std::thread tread39(sumElements, vector1000000, 875000, 999999, std::ref(resultOfSum));

	tread32.join();
	tread33.join();
	tread34.join();
	tread35.join();
	tread36.join();
	tread37.join();
	tread38.join();
	tread39.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 1000000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;


	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread40(sumElements, vector10000000, 0, 1249999, std::ref(resultOfSum));
	std::thread tread41(sumElements, vector10000000, 1250000, 2499999, std::ref(resultOfSum));
	std::thread tread42(sumElements, vector10000000, 2500000, 3749999, std::ref(resultOfSum));
	std::thread tread43(sumElements, vector10000000, 3750000, 4999999, std::ref(resultOfSum));
	std::thread tread44(sumElements, vector10000000, 5000000, 6249999, std::ref(resultOfSum));
	std::thread tread45(sumElements, vector10000000, 6250000, 7499999, std::ref(resultOfSum));
	std::thread tread46(sumElements, vector10000000, 7500000, 8749999, std::ref(resultOfSum));
	std::thread tread47(sumElements, vector10000000, 8750000, 9999999, std::ref(resultOfSum));

	tread40.join();
	tread41.join();
	tread42.join();
	tread43.join();
	tread44.join();
	tread45.join();
	tread46.join();
	tread47.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 10000000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;
	

	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread48(sumElements, vector100000000, 0, 12499999, std::ref(resultOfSum));
	std::thread tread49(sumElements, vector100000000, 12500000, 24999999, std::ref(resultOfSum));
	std::thread tread50(sumElements, vector100000000, 25000000, 37499999, std::ref(resultOfSum));
	std::thread tread51(sumElements, vector100000000, 37500000, 49999999, std::ref(resultOfSum));
	std::thread tread52(sumElements, vector100000000, 50000000, 62499999, std::ref(resultOfSum));
	std::thread tread53(sumElements, vector100000000, 62500000, 74999999, std::ref(resultOfSum));
	std::thread tread54(sumElements, vector100000000, 75000000, 87499999, std::ref(resultOfSum));
	std::thread tread55(sumElements, vector100000000, 87500000, 99999999, std::ref(resultOfSum));

	tread48.join();
	tread49.join();
	tread50.join();
	tread51.join();
	tread52.join();
	tread53.join();
	tread54.join();
	tread55.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 100000000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;

	std::cout << std::endl;
	std::cout << "Sixteen Threads";
	std::cout << std::endl;


	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread56(sumElements, vector10000, 0, 624, std::ref(resultOfSum));
	std::thread tread57(sumElements, vector10000, 625, 1249, std::ref(resultOfSum));
	std::thread tread58(sumElements, vector10000, 1250, 1874, std::ref(resultOfSum));
	std::thread tread59(sumElements, vector10000, 1875, 2499, std::ref(resultOfSum));
	std::thread tread60(sumElements, vector10000, 2500, 3124, std::ref(resultOfSum));
	std::thread tread61(sumElements, vector10000, 3125, 3749, std::ref(resultOfSum));
	std::thread tread62(sumElements, vector10000, 3750, 4374, std::ref(resultOfSum));
	std::thread tread63(sumElements, vector10000, 4375, 4999, std::ref(resultOfSum));
	std::thread tread64(sumElements, vector10000, 5000, 5624, std::ref(resultOfSum));
	std::thread tread65(sumElements, vector10000, 5625, 6249, std::ref(resultOfSum));
	std::thread tread66(sumElements, vector10000, 6250, 6874, std::ref(resultOfSum));
	std::thread tread67(sumElements, vector10000, 6875, 7499, std::ref(resultOfSum));
	std::thread tread68(sumElements, vector10000, 7500, 8124, std::ref(resultOfSum));
	std::thread tread69(sumElements, vector10000, 8125, 8749, std::ref(resultOfSum));
	std::thread tread70(sumElements, vector10000, 8750, 9374, std::ref(resultOfSum));
	std::thread tread71(sumElements, vector10000, 9375, 9999, std::ref(resultOfSum));

	tread56.join();
	tread57.join();
	tread58.join();
	tread59.join();
	tread60.join();
	tread61.join();
	tread62.join();
	tread63.join();
	tread64.join();
	tread65.join();
	tread66.join();
	tread67.join();
	tread68.join();
	tread69.join();
	tread70.join();
	tread71.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 10000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;


	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread72(sumElements, vector100000, 0, 6249, std::ref(resultOfSum));
	std::thread tread73(sumElements, vector100000, 6250, 12499, std::ref(resultOfSum));
	std::thread tread74(sumElements, vector100000, 12500, 18749, std::ref(resultOfSum));
	std::thread tread75(sumElements, vector100000, 18750, 24999, std::ref(resultOfSum));
	std::thread tread76(sumElements, vector100000, 25000, 31249, std::ref(resultOfSum));
	std::thread tread77(sumElements, vector100000, 31250, 37499, std::ref(resultOfSum));
	std::thread tread78(sumElements, vector100000, 37500, 43749, std::ref(resultOfSum));
	std::thread tread79(sumElements, vector100000, 43750, 49999, std::ref(resultOfSum));
	std::thread tread80(sumElements, vector100000, 50000, 56249, std::ref(resultOfSum));
	std::thread tread81(sumElements, vector100000, 56250, 62499, std::ref(resultOfSum));
	std::thread tread82(sumElements, vector100000, 62500, 68749, std::ref(resultOfSum));
	std::thread tread83(sumElements, vector100000, 68750, 74999, std::ref(resultOfSum));
	std::thread tread84(sumElements, vector100000, 75000, 81249, std::ref(resultOfSum));
	std::thread tread85(sumElements, vector100000, 81250, 87499, std::ref(resultOfSum));
	std::thread tread86(sumElements, vector100000, 87500, 93749, std::ref(resultOfSum));
	std::thread tread87(sumElements, vector100000, 93750, 99999, std::ref(resultOfSum));

	tread72.join();
	tread73.join();
	tread74.join();
	tread75.join();
	tread76.join();
	tread77.join();
	tread78.join();
	tread79.join();
	tread80.join();
	tread81.join();
	tread82.join();
	tread83.join();
	tread84.join();
	tread85.join();
	tread86.join();
	tread87.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 100000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;



	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread88(sumElements, vector1000000, 0, 62499, std::ref(resultOfSum));
	std::thread tread89(sumElements, vector1000000, 62500, 124999, std::ref(resultOfSum));
	std::thread tread90(sumElements, vector1000000, 125000, 187499, std::ref(resultOfSum));
	std::thread tread91(sumElements, vector1000000, 187500, 249999, std::ref(resultOfSum));
	std::thread tread92(sumElements, vector1000000, 250000, 312499, std::ref(resultOfSum));
	std::thread tread93(sumElements, vector1000000, 312500, 374999, std::ref(resultOfSum));
	std::thread tread94(sumElements, vector1000000, 375000, 437499, std::ref(resultOfSum));
	std::thread tread95(sumElements, vector1000000, 437500, 499999, std::ref(resultOfSum));
	std::thread tread96(sumElements, vector1000000, 500000, 562499, std::ref(resultOfSum));
	std::thread tread97(sumElements, vector1000000, 562500, 624999, std::ref(resultOfSum));
	std::thread tread98(sumElements, vector1000000, 625000, 687499, std::ref(resultOfSum));
	std::thread tread99(sumElements, vector1000000, 687500, 749999, std::ref(resultOfSum));
	std::thread tread100(sumElements, vector1000000, 750000, 812499, std::ref(resultOfSum));
	std::thread tread101(sumElements, vector1000000, 812500, 874999, std::ref(resultOfSum));
	std::thread tread102(sumElements, vector1000000, 875000, 937499, std::ref(resultOfSum));
	std::thread tread103(sumElements, vector1000000, 937500, 999999, std::ref(resultOfSum));

	tread88.join();
	tread89.join();
	tread90.join();
	tread91.join();
	tread92.join();
	tread93.join();
	tread94.join();
	tread95.join();
	tread96.join();
	tread97.join();
	tread98.join();
	tread99.join();
	tread100.join();
	tread101.join();
	tread102.join();
	tread103.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 1000000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;


	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread104(sumElements, vector10000000, 0, 624999, std::ref(resultOfSum));
	std::thread tread105(sumElements, vector10000000, 625000, 1249999, std::ref(resultOfSum));
	std::thread tread106(sumElements, vector10000000, 1250000, 1874999, std::ref(resultOfSum));
	std::thread tread107(sumElements, vector10000000, 1875000, 2499999, std::ref(resultOfSum));
	std::thread tread108(sumElements, vector10000000, 2500000, 3124999, std::ref(resultOfSum));
	std::thread tread109(sumElements, vector10000000, 3125000, 3749999, std::ref(resultOfSum));
	std::thread tread110(sumElements, vector10000000, 3750000, 4374999, std::ref(resultOfSum));
	std::thread tread111(sumElements, vector10000000, 4375000, 4999999, std::ref(resultOfSum));
	std::thread tread112(sumElements, vector10000000, 5000000, 5624999, std::ref(resultOfSum));
	std::thread tread113(sumElements, vector10000000, 5625000, 6249999, std::ref(resultOfSum));
	std::thread tread114(sumElements, vector10000000, 6250000, 6874999, std::ref(resultOfSum));
	std::thread tread115(sumElements, vector10000000, 6875000, 7499999, std::ref(resultOfSum));
	std::thread tread116(sumElements, vector10000000, 7500000, 8124999, std::ref(resultOfSum));
	std::thread tread117(sumElements, vector10000000, 8125000, 8749999, std::ref(resultOfSum));
	std::thread tread118(sumElements, vector10000000, 8750000, 9374999, std::ref(resultOfSum));
	std::thread tread119(sumElements, vector10000000, 9375000, 9999999, std::ref(resultOfSum));

	tread104.join();
	tread105.join();
	tread106.join();
	tread107.join();
	tread108.join();
	tread109.join();
	tread110.join();
	tread111.join();
	tread112.join();
	tread113.join();
	tread114.join();
	tread115.join();
	tread116.join();
	tread117.join();
	tread118.join();
	tread119.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 10000000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;


	resultOfSum = 0;
	begin = std::chrono::high_resolution_clock::now();

	std::thread tread120(sumElements, vector100000000, 0, 6249999, std::ref(resultOfSum));
	std::thread tread121(sumElements, vector100000000, 6250000, 12499999, std::ref(resultOfSum));
	std::thread tread122(sumElements, vector100000000, 12500000, 18749999, std::ref(resultOfSum));
	std::thread tread123(sumElements, vector100000000, 18750000, 24999999, std::ref(resultOfSum));
	std::thread tread124(sumElements, vector100000000, 25000000, 31249999, std::ref(resultOfSum));
	std::thread tread125(sumElements, vector100000000, 31250000, 37499999, std::ref(resultOfSum));
	std::thread tread126(sumElements, vector100000000, 37500000, 43749999, std::ref(resultOfSum));
	std::thread tread127(sumElements, vector100000000, 43750000, 49999999, std::ref(resultOfSum));
	std::thread tread128(sumElements, vector100000000, 50000000, 56249999, std::ref(resultOfSum));
	std::thread tread129(sumElements, vector100000000, 56250000, 62499999, std::ref(resultOfSum));
	std::thread tread130(sumElements, vector100000000, 62500000, 68749999, std::ref(resultOfSum));
	std::thread tread131(sumElements, vector100000000, 68750000, 74999999, std::ref(resultOfSum));
	std::thread tread132(sumElements, vector100000000, 75000000, 81249999, std::ref(resultOfSum));
	std::thread tread133(sumElements, vector100000000, 81250000, 87499999, std::ref(resultOfSum));
	std::thread tread134(sumElements, vector100000000, 87500000, 93749999, std::ref(resultOfSum));
	std::thread tread135(sumElements, vector100000000, 93750000, 99999999, std::ref(resultOfSum));

	tread120.join();
	tread121.join();
	tread122.join();
	tread123.join();
	tread124.join();
	tread125.join();
	tread126.join();
	tread127.join();
	tread128.join();
	tread129.join();
	tread130.join();
	tread131.join();
	tread132.join();
	tread133.join();
	tread134.join();
	tread135.join();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "Sum of all elements in vector of size 100000000" << std::endl;
	std::cout << "Sum result " << resultOfSum << std::endl;
	std::cout << "Time taken " << duration.count() << std::endl;
}

std::vector<int> generateVector(int size) 
{
	std::vector<int> resultingVector;

	for (int i = 0; i < size; i++)
	{
		resultingVector.push_back(std::rand() % 5);
	}

	return resultingVector;
}

void sumElements(std::vector<int> inVector, int startIndex, int endIndex, int& sumResult) 
{
	int tempResult =0;

	for (int i = startIndex; i <= endIndex; i++)
	{
		tempResult += inVector[i];
	}
	threadMutex.lock();
	sumResult += tempResult;
	threadMutex.unlock();

}