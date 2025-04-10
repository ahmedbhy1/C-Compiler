int main() {
    int x = 1;
    {
        int y = 2;
        {
            int x = 100;
            y = y + x;   
        }
        return y;        
    }
}
