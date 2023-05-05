main:
	g++ vector.h main.cpp -O3 -o vector.exe -std=c++20
run:
	./vector.exe
member:
	g++ -std=c++20 -O3 vector.h ./Tests/Member_functions.cpp -o ./Tests/bin/member.exe
run_member:
	./Tests/bin/member.exe