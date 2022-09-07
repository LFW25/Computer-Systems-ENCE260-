    /* Question 1 */
    SignMag_t val1 = {false, 15};
    printf("%s%hu\n", val1.isNegative ? "-" : "+", val1.magnitude); 
    /* +15 */
    SignMag_t val2 = {.isNegative = true, .magnitude=32};
    printf("%s%hu\n", val2.isNegative ? "-" : "+", val2.magnitude);
    /* -32 */
    SignMag_t val3 = {.isNegative = false, .magnitude=65535};
    printf("%s%hu\n", val3.isNegative ? "-" : "+", val3.magnitude);
    /* +65535 */
    SignMag_t val4 = {.isNegative = true, .magnitude=0};
    printf("%s%hu\n", val4.isNegative ? "-" : "+", val4.magnitude);
    /* -0 */
    SignMag_t val5 = {.isNegative = false, .magnitude=0};
    printf("%s%hu\n", val5.isNegative ? "-" : "+", val5.magnitude);
    /* +0 */


    /* Question 2 */
    SignMag_t val1 = signMag_init(false, 32);
    signMag_print(val1);
    /* 32 */
    SignMag_t val2 = signMag_init(true, 42);
    signMag_print(val2);
    /* -42 */
    SignMag_t val3 = signMag_init(false, 65535);
    signMag_print(val3);
    /* 65535 */
    SignMag_t val4 = signMag_init(false, 0);
    signMag_print(val4);
    /* 0 */
    SignMag_t val5 = signMag_init(true, 0);
    signMag_print(val5);
    /* -0 */

/* Question 3 */
SignMag_t val1 = signMag_read();
printf("%s%hu ", val1.isNegative ? "-" :"+", val1.magnitude);
/* Input: 2345      Expected: +2345         Got: +2345*/


SignMag_t val2 = signMag_read();
printf("%s%hu ", val2.isNegative ? "-" :"+", val2.magnitude);
/* Input: -2368     Expected: -2368         Got: -2368*/	
	

SignMag_t val3 = signMag_read();
printf("%s%hu ", val3.isNegative ? "-" :"+", val3.magnitude);
/* Input: +12345    Expected: +12345        Got: +12345*/	
	

SignMag_t val = signMag_read();
printf("%s%hu ", val.isNegative ? "-" :"+", val.magnitude);
val = signMag_read();
printf("%s%hu ", val.isNegative ? "-" :"+", val.magnitude);
val = signMag_read();
printf("%s%hu ", val.isNegative ? "-" :"+", val.magnitude);
/* Input: 1 -1 3    Expected: +1 -1 +3      Got: -0 +65535 +65535*/
	

SignMag_t val = signMag_read();
printf("%s%hu ", val.isNegative ? "-" :"+", val.magnitude);
val = signMag_read();
printf("%s%hu ", val.isNegative ? "-" :"+", val.magnitude);
val = signMag_read();
printf("%s%hu ", val.isNegative ? "-" :"+", val.magnitude);
/* Input: 7q8q-235462 Expected: +7 +8 -65535    Got: -0 +65535 +65535*/
	

SignMag_t val = signMag_read();
printf("%s%hu ", val.isNegative ? "-" :"+", val.magnitude);
/* Input: rubbish   Expected: -0 Got: -0*/

/* Question 4 */
SignMag_t val1 = {false, 5};
SignMag_t val2 = {false, 3};
SignMag_t sum = signMag_sum(val1, val2);
printf("%s%hu ", sum.isNegative ? "-" :"+", sum.magnitude);
/* +8 */

SignMag_t val1 = {true, 5};
SignMag_t val2 = {true, 3};
SignMag_t sum = signMag_sum(val1, val2);
printf("%s%hu ", sum.isNegative ? "-" :"+", sum.magnitude);
/* -8 */

SignMag_t val1 = {true, 5};
SignMag_t val2 = {false, 18};
SignMag_t sum = signMag_sum(val1, val2);
printf("%s%hu ", sum.isNegative ? "-" :"+", sum.magnitude);
/* +13 */

SignMag_t val1 = {false, 5};
SignMag_t val2 = {false, 65535};
SignMag_t sum = signMag_sum(val1, val2);
printf("%s%hu ", sum.isNegative ? "-" :"+", sum.magnitude);
/* +65535 */

SignMag_t val1 = {true, 5};
SignMag_t val2 = {true, 65535};
SignMag_t sum = signMag_sum(val1, val2);
printf("%s%hu ", sum.isNegative ? "-" :"+", sum.magnitude);
/* -65535 */

SignMag_t val1 = {false, 92};
SignMag_t val2 = {true, 7};
SignMag_t sum = signMag_sum(val1, val2);
printf("%s%hu ", sum.isNegative ? "-" :"+", sum.magnitude);
/* +85 */


/* Question 5 */
SignMag_t array1[2];
array1[0].isNegative = false; 
array1[0].magnitude = 5;
array1[1].isNegative = false;
array1[1].magnitude = 2;
SignMag_t ans1 = signMag_accumulate(array1, 2);
printf("%s%hu ", ans1.isNegative ? "-" : "+", ans1.magnitude);
/* +7 */

    SignMag_t array2[3];
    array2[0].isNegative = false; 
    array2[0].magnitude = 5;
    array2[1].isNegative = false;
    array2[1].magnitude = 2;
    array2[2].isNegative = true;
    array2[2].magnitude = 1;
    SignMag_t ans2 = signMag_accumulate(array2, 3);
    printf("%s%hu ", ans2.isNegative ? "-" : "+", ans2.magnitude);
    /* +6 */

    SignMag_t array3[100];
    for(size_t i=0; i < 100; i++) {
        array3[i].isNegative = i%2 ? true : false;
        array3[i].magnitude = (uint16_t)i;
    }
    SignMag_t ans3 = signMag_accumulate(array3, 100);
    printf("%s%hu ", ans3.isNegative ? "-" : "+", ans3.magnitude);
    /* -50 */


/* Question 7 */
    SignMag_t sm1 = {false, 3};
    SignMag_t sm2 = {false, 5};
    SignMag_t* max = NULL;
    bool sat = signMag_max(&sm1, &sm2, &max);
    printf("%s %s%hu ", sat ? "(SAT)" : " ", max->isNegative ? "-" : "+", max->magnitude);
    /* +5 */

    SignMag_t sm1 = {true, 3};
    SignMag_t sm2 = {true, 5};
    SignMag_t* max = NULL;
    bool sat = signMag_max(&sm1, &sm2, &max);
    printf("%s %s%hu ", sat ? "(SAT)" : " ", max->isNegative ? "-" : "+", max->magnitude);
    /* -3 */

    SignMag_t sm1 = {true, 3};
    SignMag_t sm2 = {false, 65535};
    SignMag_t* max = NULL;
    bool sat = signMag_max(&sm1, &sm2, &max);
    printf("%s %s%hu ", sat ? "(SAT)" : " ", max->isNegative ? "-" : "+", max->magnitude);
    /* (SAT) +65535 */

/* Question 8 */
SignMag_t array[3] = {signMag_init(true, 50), signMag_init(false, 50), signMag_init(false, 1)};

SignMag_t* max = arrayMax(array, 3, &signMag_max);
printf("Max of Numbers: ");
signMag_print(*max);
/* Max of Numbers: 50 */