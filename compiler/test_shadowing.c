int main() {
    int x = 10;
    {
        int x = 5;  
        return x;   
    }
    return x;  
}