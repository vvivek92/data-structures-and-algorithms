
// wont work as static variables must be initialised before main is excuted
int init(void) {
    return 50;
}


int main(void) {
    static int i = init();
}
