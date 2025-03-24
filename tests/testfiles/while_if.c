int main() {
    int x = 0;
    int y = 0;
    while (x < 50) {
        if (x < 12) {
            x = x + 2;
            x = x - 1;
        } 
        else{
            x = x + 3;
        }
        y = y + 1;
    }
    return y;

}
