main:
	g++ vector.h main.cpp -O3 -o vector.exe -std=c++20
run:
	./vector.exe
member:
	g++ -std=c++20 -O3 vector.h ./Tests/Member_functions.cpp -o ./Tests/bin/member.exe
run_member:
	./Tests/bin/member.exe
element:
	g++ -std=c++20 -O3 vector.h ./Tests/element_access.cpp -o ./Tests/bin/element.exe
run_element:
	./Tests/bin/element.exe
iterator:
	g++ -std=c++20 -O3 vector.h ./Tests/iterators.cpp -o ./Tests/bin/iterators.exe
run_iterator:
	./Tests/bin/iterators.exe
capacity:
	g++ -std=c++20 -O3 vector.h ./Tests/capacity.cpp -o ./Tests/bin/capacity.exe
run_capacity:
	./Tests/bin/capacity.exe
non-member:
	g++ -std=c++20 -O3 vector.h ./Tests/non-member.cpp -o ./Tests/bin/non-member.exe
run_non-member:
	./Tests/bin/non-member.exe
push_back:
	g++ -std=c++20 -O3 vector.h ./Tests/push_back.cpp -o ./Tests/bin/push_back.exe
run_push_back:
	./Tests/bin/push_back.exe
modifiers:
	g++ -std=c++20 -O3 vector.h ./Tests/modifiers.cpp -o ./Tests/bin/modifiers.exe
run_modifiers:
	./Tests/bin/modifiers.exe