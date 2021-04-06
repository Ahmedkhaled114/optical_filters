/**
 * File:   optical_filters.c
 * Author: Ahmed khaled
 *
 * Created on April 5, 2021, 8:39 PM
 **/

/** Section: Include **/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/** Section: Macro Declarations **/

#define zero_init 0

/** Section: Global variables Declarations **/

unsigned int arr [][3] ;


 float gaussian [][3] = {{0.0625,0.125,0.0625},
                          {0.125,0.250,0.125 },
                          {0.0625,0.125,0.0625}};

unsigned int weighted_average [][3] =  {{1,1,1},
                                        {1,2,1},
                                        {1,1,1}};

/** Section: Function declarations **/

float mean_filter (int arr [3][3]);
float gaussian_filter (int arr [3][3] , float g_arr [3][3]);
void enter_the_data (int arr_elem_2 [][3] , int size_1 , int size_2);
void print_arr_elements_2d ( unsigned int arr_elem_2 [][3] , int size_1 , int size_2 );
float weighted_average_filter (int arr [3][3] , int g_arr [3][3]);
int median_filter (int * arr);
int maximum_filter (int  arr[3][3] );
int minumim_filter (int  arr[3][3] );
int descending_order (int*arr );
int convert_2d_to_1d(int *arr_2d);


/** main Function **/
int main()
{
    enter_the_data ( arr , 3 , 3);
printf("-----------------------------------------\n");

float var_2 = gaussian_filter (arr , gaussian);
printf ("Element [2][2] for Gaussian_filter = %0.1f\n" , var_2);

float var_3 = weighted_average_filter (arr , weighted_average);
printf ("Element [2][2] for Weighted_Average_filter = %0.1f\n" , var_3);
float var_0 =mean_filter(arr);
 printf ("Element [2][2] for Mean_filter = %0.1f\n" , var_0);

int var_1 = median_filter (&arr );
printf ("Element [2][2] for Median_filter = %i\n" , var_1);

int var_4 = maximum_filter (arr );
printf ("Element [2][2] for Maximum_filter  = %i\n" , var_4);

int var_5 = minumim_filter (arr );
printf ("Element [2][2] for Minumim_filter  = %i\n" , var_5);


sleep(300000);

    return 0;
}



//------------------------------------------------------------------------------------------

void print_arr_elements_2d (unsigned int arr_elem_2 [][3] , int size_1 , int size_2 ){


    int counter_1=0 , counter_2=0 ;
    for ( counter_1=0; counter_1 < size_1; counter_1++) {
       for ( counter_2=0; counter_2 < size_2 ; counter_2++){

        printf("%i\t", arr_elem_2 [counter_1][counter_2] );


       }
printf("\n");
    }
}

//------------------------------------------------------------------------------------------

void enter_the_data (int arr_elem_2 [][3] , int size_1 , int size_2){
         printf("enter_ur_data ...\n");
  unsigned int counter_r=zero_init;
  unsigned int counter_c=zero_init;

  for (counter_r=zero_init ; counter_r<size_1 ; counter_r++){
        for (counter_c =zero_init ; counter_c <size_2 ; counter_c++){
            printf("enter value for pos [%i][%i] =", counter_r+1 , counter_c+1);
            scanf ("%i,%i" , & arr[counter_r][counter_c]);
        }
     }
     printf("-----------------------------------------\n");
     printf("The Entered Data ..\n");
     print_arr_elements_2d(arr_elem_2,3,3);
  }

//-------------------------------------------------------------------------------------------


float mean_filter (int arr [3][3]){

unsigned int counter_r=zero_init;
unsigned int counter_c=zero_init;
float sum = zero_init ;

  for (counter_r=zero_init ; counter_r<3 ; counter_r++){
        for (counter_c =zero_init ; counter_c <3 ; counter_c++){

            sum+= arr[counter_r][counter_c];

        }
  }
  sum/=9;

  return sum;
};

//---------------------------------------------------------------------------------------------

int median_filter (int * arr ){

  int counter_1 , counter_2, temp ;

        for (counter_1 = 0; counter_1 < 9; ++counter_1)
        {
            for (counter_2 = counter_1 + 1; counter_2 < 9; ++counter_2)
            {
                if (arr[counter_1] < arr[counter_2])
                {
                    temp = arr[counter_1];
                    arr[counter_1] = arr[counter_2];
                    arr[counter_2] = temp;
                }
            }
        }
/*
        printf("The numbers arranged in descending order\n");

        for (counter_1 = 0; counter_1 < 9; ++counter_1)
        {
            printf("%d\n", arr[counter_1]);
        }*/

      return arr[4];


};

//---------------------------------------------------------------------------------------------
float gaussian_filter (int arr [3][3] , float g_arr [3][3]){

unsigned int counter_r=zero_init;
unsigned int counter_c=zero_init;
 float result_of_product [3][3];
float new_index = zero_init;

  for (counter_r=zero_init ; counter_r<3 ; counter_r++){
        for (counter_c =zero_init ; counter_c <3 ; counter_c++){
      result_of_product [counter_r][ counter_c ]  = arr[counter_r][counter_c]
      * g_arr[counter_r][counter_c] ;

        }
      }

/*
int counter_1=0 , counter_2=0 ;
    for ( counter_1=0; counter_1 <3; counter_1++) {
       for ( counter_2=0; counter_2 < 3 ; counter_2++){

        printf(" result_of_product %f\t", result_of_product [counter_1][counter_2] );


       }
printf("\n");
    }
*/

       for (counter_r=zero_init ; counter_r<3 ; counter_r++){
        for (counter_c =zero_init ; counter_c <3 ; counter_c++){

        new_index+=result_of_product [counter_r][ counter_c ];

    }
   }
  return new_index ;
};

//---------------------------------------------------------------------------------------------

float weighted_average_filter (int arr [3][3] , int g_arr [3][3]){

unsigned int counter_r=zero_init;
unsigned int counter_c=zero_init;
int result_of_product [3][3];
float new_index = zero_init;
float ratio_index = 0.11111;

  for (counter_r=zero_init ; counter_r<3 ; counter_r++){
        for (counter_c =zero_init ; counter_c <3 ; counter_c++){
      result_of_product [counter_r][ counter_c ]  = arr[counter_r][counter_c]
      * g_arr[counter_r][counter_c] ;

        }
       }

       for (counter_r=zero_init ; counter_r<3 ; counter_r++){
        for (counter_c =zero_init ; counter_c <3 ; counter_c++){

        new_index+=result_of_product [counter_r][ counter_c ];

    }
   }
   new_index*=ratio_index;
  return new_index ;
};

//---------------------------------------------------------------------------------------------

int maximum_filter (int  arr[3][3] ){

int max_element= arr[0][0];
unsigned int counter_r=zero_init;
unsigned int counter_c=zero_init;
 for (counter_r=zero_init ; counter_r<3 ; counter_r++){
        for (counter_c =zero_init ; counter_c <3 ; counter_c++){

   if (arr[counter_r][counter_c] > max_element)
        max_element = arr[counter_r][counter_c];

    }
}
  return max_element;

}
//---------------------------------------------------------------------------------------------

int minumim_filter (int  arr[3][3] ){

int min_element= arr[0][0];
unsigned int counter_r=zero_init;
unsigned int counter_c=zero_init;
 for (counter_r=zero_init ; counter_r<3 ; counter_r++){
        for (counter_c =zero_init ; counter_c <3 ; counter_c++){

   if (arr[counter_r][counter_c] < min_element)
        min_element = arr[counter_r][counter_c];

    }
}
  return min_element;

}

/*
 *--------------------------------------------------------------------------------------------
*/

   int descending_order (int*arr ){

        int counter_1,counter_2, temp ;

        for (counter_1 = 0; counter_1 < 9; ++counter_1)
        {
            for (counter_2 = counter_1 + 1; counter_2 < 9; ++counter_2)
            {
                if (arr[counter_1] < arr[counter_2])
                {
                    temp = arr[counter_1];
                    arr[counter_1] = arr[counter_2];
                    arr[counter_2] = temp;
                }
            }
        }

        printf("The numbers arranged in descending order are given below\n");

        for (counter_1 = 0; counter_1 < 9; ++counter_1)
        {
            printf("%d\n", arr[counter_1]);
        }

      return arr[4];

        }

//-------------------------------------------------------------------------------------------

int convert_2d_to_1d(int *arr_2d ) {

unsigned int counter_r=zero_init;
unsigned int counter_c=zero_init;
unsigned int arr_1d [9];
unsigned int var ;

  for (counter_r=zero_init ; counter_r<3 ; counter_r++){
        for (counter_c =zero_init ; counter_c <3 ; counter_c++){

          arr_1d [var]= arr[counter_r][counter_c];
          var++;
    }
  }

  printf("1D-Array\n");
	for(counter_r=zero_init ; counter_r<9; counter_r++)
		printf("%d ", arr_1d [counter_r]);
	return arr_1d;
}

/*
 *--------------------------------------------------------------------------------------------
 * -------------------------------------------------------------------------------------------
*/
