
/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
design an algorithm to find the maximum profit. */

public class Solution {
    public int maxProfit(int[] prices) {
     
     
     if (prices.length == 0)
        return 0;
     
     int maxPrice = 0;
     int minPrice = prices[0];
     int profit;
     
     for (int i = 1; i<prices.length; i++)
     {
        profit = prices[i] - minPrice;
         
        if (maxPrice < profit)
            maxPrice = profit;
        
        if(minPrice > prices[i])
            minPrice = prices[i];
    
     }
     
     return maxPrice;
    }
}
