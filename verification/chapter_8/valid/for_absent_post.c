int main(void) {
    int a = -8388609;
    for (; a % 5 != 0;) {
        a = a + 1;
    }
    return a % 5 || a > 0;
}
