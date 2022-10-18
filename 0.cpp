#include<iostream>
#include<type_traits>
// using namespace std;


// // template definition
// template <typename KEY, typename DATA>
// struct TestMap{
// 	TestMap(){std::cout<<"Test_map constructed\n";}
// 	// default implementation
// };

// // partial specialization
// template <typename DATA>
// struct TestMap<int, DATA>{
// 	TestMap(){std::cout<<"TestMap <int, DATA> constructed\n";}
// 	// int implementation
// };

// // full specialization
// template<>
// struct TestMap<int, int>{
// 	TestMap(){std::cout<<"TestMap <int, int> constructed\n";}
// };

template<typename T>
struct is_pointer<T>{
	static constexpr bool value = false;
}


template<typename T>
void print1(T t){
	if constexpr(is_pointer<T>::value){
		std::cout << *t;
	}
	else{
		std::cout << t;
	}
}

template<typename A, typename B, typename C>
void print3(A a, B b, C c){
	print1(a);
	std::cout << ", ";
	print1(b);
	std::cout << ", ";
	print1(c);
	std::cout << "\n";
}


int main(){
	int a = 3;
	int *pa = &a;
	std::string s = "Hello";
	print3(a, pa, s);


	// TestMap<int, int> test1;
	// TestMap<int, string> test2;
	// TestMap<string, string> test3;
}
