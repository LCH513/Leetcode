int maxProfit(int* prices, int pricesSize){
    int *price = malloc(sizeof(int) * pricesSize-1);
    int total = 0;
    for(int i = 0; i < pricesSize-1; i++){
        price[i] = prices[i+1] - prices[i];
    }
    for(int i = 0; i < pricesSize-1; i++){
        if(price[i] > 0){
            total += price[i];
        }
    }
    return total;
}
