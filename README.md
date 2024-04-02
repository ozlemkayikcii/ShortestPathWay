# ShortestPathWay


In this project, given a matrix of integers where each cell represents a weight, you are tasked with writing a program that finds a continuous path that combines any element of the first row with any element of the last row in the matrix, aiming to minimize the sum of items along the path. When visualized conventionally, the path strictly moves downwards. We can approach this problem gradually. What if the matrix had only one row? In this scenario, the minimum weight path would simply be the minimum weight item from the first row. What if we added one more row? In this case, we could find the minimum path to a particular item in the row by identifying the lowest value in the first row and then traversing to the second row from that item. This analysis continues as we add more rows to the matrix until it is fully populated. The outcome of this process is another matrix entirely filled with minimum path weights to each item.

![image](https://user-images.githubusercontent.com/84348306/226485227-d7ccf436-e635-4b1e-883d-8607640044ab.png)
![image](https://user-images.githubusercontent.com/84348306/226485510-4e10a593-40ac-4a46-823d-2c5c1e6cb186.png)

![image](https://user-images.githubusercontent.com/84348306/226485355-b3241e90-5967-41e1-8f5f-caefc008e2f2.png)
