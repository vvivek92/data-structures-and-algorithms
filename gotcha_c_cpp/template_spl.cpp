


template <class T>
void func(T a);

template<>
void func<int>(int a) {
   
}


int main() {
    func(2.0); //doesn't compile. we are avoiding implcit conversion from double               //to int using template specialisation. (Interesting hack)

}

