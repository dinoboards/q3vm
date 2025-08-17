int main(void) {
    int ret;
    int i;
    for (i = 0; i < 4; i = i + 1)
        ret = foo();
    return ret;
}


int foo(void) {
    /* If a static variable has no explicit initializer,
     * it's initialized to zero.
     */
    static int x;
    x = x + 1;
    return x;
}

