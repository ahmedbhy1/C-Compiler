int main() {
    int x = 0;
    int y = 0;
    while (x < 5) {
        if (y%2 == 0){
            x = x + 1;
        }
        y = y + 1;
    }
    return x+y;
}
