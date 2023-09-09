#include<stdio.h>
#include<math.h>


    void cofactorfinder(int matrix[][3] , int n);
    void adjointfinder(int matrix[][3],int n ,int cofactor[][3], int m );
    int determinantfinder(int matrix[][3], int n);
    void inversefinder(int adjoint[][3], int n , int matrix[][3] ,int m);


    int main() {
        //heading for the program
        printf("\t\tMatrix Inverse Finder\n");
        printf("__________________________________________________\n");



        //Taking in elements for given matrix
        int matrix[3][3];
        for(int i=0 ; i<3 ;i++) {
            for(int j=0 ; j<3 ; j++) {
                printf("Please Enter element for row[%d],column[%d]",i+1,j+1);
                scanf("%d",&matrix[i][j]);
                printf("\n");
            }
            
        }

        //Printing the given matrix
        for(int i=0 ; i<3 ; i++) {
            for(int j=0 ; j<3 ; j++) {
                printf("%5d",matrix[i][j]);

            }
            printf("\n");
        }

        //confirming the given matrix
        char confirmation[5];
        printf("\nIs this your given matrix ?  --  Type (Yes/No) :");
        fgets(confirmation,5,stdin);

        //Proceeding with given matrix ---OR--- Re-entering the matrix
        if (confirmation == "Yes" || "yes") {

            //calling the cofactorfinder function for the given matrix
            cofactorfinder(matrix[][3] ,3);    
        } 

        else if (confirmation == "No" || "no") {
            //going for re-collection of elements of matrix as per user's request
            printf("\n Please re-enter correct matrix.....\n\n");
            main();

        }
        else {
            //procedure for invalid response
            printf("\nYour response is not valid\nRestaring the program..........\n");
            main();
        }

        return 0;
    }





    void cofactorfinder(int matrix[][3] , int n) {

        int cofactor[3][3];

        //calculating and filling up 1st row cofactors 
        cofactor[0][0]= (1) * (matrix[0][0]) * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]));
        cofactor[0][1]= (-1) * (matrix[0][1]) * ((matrix[1][0] * matrix[2][2]) - (matrix[2][0] * matrix[1][2]));
        cofactor[0][2]= (1) * (matrix[0][2]) * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]));

        //calculating and filling up 2nd row cofactors
        cofactor[1][0]= (-1) * (matrix[1][0]) * ((matrix[0][1] * matrix[2][2]) - (matrix[0][2] * matrix[2][1]));
        cofactor[1][1]= (1) * (matrix[1][1]) * ((matrix[0][0] * matrix[2][2]) - (matrix[0][2] * matrix[2][0]));
        cofactor[1][2]= (-1) * (matrix[1][2]) * ((matrix[0][0] * matrix[2][1]) - (matrix[0][1] * matrix[2][0]));

        //calculating and filling up 3rd row cofactors
        cofactor[2][0]= (1) * (matrix[2][0]) * ((matrix[0][1] * matrix[1][2]) - (matrix[0][2] * matrix[1][1]));
        cofactor[2][1]= (-1) * (matrix[2][1]) * ((matrix[0][0] * matrix[1][2]) - (matrix[0][2] * matrix[1][0]));
        cofactor[2][2]= (1) * (matrix[2][2]) * ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));

        //calling the adjoint finder functio wit arguments as the given matrix and the cofactors
        adjointfinder(matrix , 3, cofactor ,3);

        // Here, we have given the user's matrix as an argument to the function for passing it to another continuos function for intialisation although this matrix has no use in the adjoint function

    }





    void adjointfinder(int matrix[][3],int n  ,int cofactor[][3],int m) {

        int adjoint[3][3]; //creating the adjoint matrix 

        //arranging the cofactors in adjoint format i.e,trnsposing the cofactor matrix...
        for(int i=0 ; i<3 ; i++) {

            for (int j=0 ; j<3 ; j++) {
                
                adjoint[i][j] = cofactor[j][i];

            }
        }

        // Now, printing our adjoint matrix 

        printf("\nThe Adjoint of your given matrix is : \n\n");

        for(int i=0 ; i<3 ; i++) {

            for(int j=0 ; j<3 ; j++) {

                printf("%5d", adjoint[i][j]);
            }
            printf("\n");
        }

        printf("\n");



        // Now calling our inversefinder funcion
        inversefinder(adjoint,3 ,matrix,n);

    }





    void inversefinder(int adjoint[][3], int n , int matrix[][3] ,int m) {

        float inverse[3][3];
        int det = determinantfinder(matrix,m);

        //calculating the values of elements of the inverse matrix...
        for(int i=0 ; i<3 ; i++) {
            for(int j=0 ; j<3 ; j++){

                inverse[i][j]= (adjoint[i][j])/det ;               
            }
        }

        //now printing our final inverse matrix.....
        printf("\nThe inverse of the given matrix is : \n");

        for(int i=0 ; i<3 ; i++) {

            for(int j=0 ; j<3 ; j++) {

                printf("\t%.2ff",inverse[i][j]);
            }
            printf("\n");
        }

        
    }





    int determinantfinder(int matrix[][3], int n) {

        //declaring an integer to store the final value of determinanat..
        int deter;

        //defining the values of cofactors for calculation of feterminant...
        int cofa1 = (1)*(matrix[0][0])*((matrix[1][1]*matrix[2][2])-(matrix[1][2]*matrix[2][1]));
        int cofa2 = (-1)*(matrix[0][1])*((matrix[1][0]*matrix[2][2])-(matrix[1][2]*matrix[2][0]));
        int cofa3 = (1)*(matrix[0][2])*((matrix[1][0]*matrix[2][1])-(matrix[1][1]*matrix[2][0]));

        deter = cofa1 + cofa2 +cofa3;
        //the formula of determinant


        return deter;
    }
