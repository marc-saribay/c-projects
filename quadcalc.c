#include <stdio.h>
#include <math.h>

int main(void)
{
  /* Declare variables */
  double A, B, C, DISC, R1, R2;
  char x = 'Y';
  int ready = 0;

  /* Program Heading */
  printf("\n**************************************************\n");
  printf("* QUADRATIC EQUATION CALCULATOR (C Version)      *\n");
  printf("* (c)2001 by Marc Christian Saribay (2000-46388) *\n");
  printf("**************************************************\n");

  /* Main Program */
  while (((x == 'Y')||(x == 'y'))&&(ready == 0)) {
    printf("%s", "\nEnter three numbers\n");
    printf("%s", "corresponding to A, B, C, in the quadratic equation:\n");

  /* Read inputs */
    scanf("%lf%lf%lf", &A, &B, &C);

  /* Confirm values */
    printf("%s","\nHere are the values you entered\n");
    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("C = %lf\n", C);
    x = 'g';
    while ((x != 'y')&&(x != 'Y')&&(x != 'n')&&(x != 'N')) {
      printf("%s", "\nChange the values? (Y/N): ");
      scanf("%s", &x);
      if ((x == 'y')||(x == 'Y')) {
	ready = 0;
      }
      else if ((x == 'n')||(x == 'N')) {
	ready = 1;
      }
    }

    /* Process */
    if (ready == 1) {
      if (A == 0) {
	if (B == 0) {
	  printf("\nInvalid equation\n");
	}
	else {
	  R1 = (-C)/B;
	  printf("\nThis is a linear equation\n");
	  printf("X = %2.10e\n", R1);
	}
	ready = 0;
      }
      else {
	DISC = (pow(B, 2.0))-(4*A*C);
	if (DISC == 0) {
	  R1 = (-B)/(2*A);
	  printf("%s", "\nThis is a quadratic equation\n[One real root]\n");
	  printf("X = %2.10e\n", R1);
	}
	else if (DISC > 0) {
	  R1 = ((-B) + sqrt(DISC))/(2*A);
	  R2 = ((-B) - sqrt(DISC))/(2*A);
	  printf("%s", "\nThis is a quadratic equation\n[Two real roots]\n");
	  printf("X = %2.10e\n", R1);
	  printf("X = %2.10e\n", R2);
	}
	else {
	  R1 = (-B)/(2*A);
	  R2 = (sqrt(abs(DISC)))/(2*A);
	  printf("%s", "\nThis is a quadratic equation\n[Two imaginary roots]\n");
	  printf("X = %2.10e + %2.10ei\n", R1, R2);
	  printf("X = %2.10e - %2.10ei\n", R1, R2);
	}
	ready = 0;
      }

      /* Retry Program */
      x = 'g';
      while ((x != 'y')&&(x != 'Y')&&(x != 'n')&&(x != 'N')) {
	printf("%s", "\nDo you want to enter another set of values? (Y/N): ");
	scanf("%s", &x);
      }
    }
  }

  /* Program End */
  printf("%s", "\nThanks for using my C Version of Quadratic Equation Calculator!\n");
  return 0;
}