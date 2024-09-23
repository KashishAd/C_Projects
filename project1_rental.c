// Kashish Adlakha
// This program calculates the rental charge of various equipments.
#include <stdio.h>

int main() {
  int selection, days, hours;
  

  // Prompt the user to select equipment
  printf("Please select from four equipment: 1, 2, 3, and 4\n");
  printf("Enter equipment selection: ");
  scanf("%d", &selection);

  // Check if the equipment selection is valid
  if (selection < 1 || selection > 4) {
    printf("Invalid selection. Select from 1 to 4.\n");
    return 1;
  }

  int week_cost;
  int day_cost;
  int four_hour;
  if (selection == 1) {
    week_cost = 40;
    day_cost = 10;
    four_hour = 7;
  } else if (selection == 2) {
    week_cost = 156;
    day_cost = 39;
    four_hour = 27;
  } else if (selection == 3) {
    week_cost = 348;
    day_cost = 87;
    four_hour = 61;
  } else if (selection == 4) {
    week_cost = 336;
    day_cost = 84;
    four_hour = 59;
  }
  // Prompt the user to enter days and hours
  printf("Enter days: ");
  scanf("%d", &days);
  printf("Enter hours: ");
  scanf("%d", &hours);

  int week;
  if (days > 7) {
    week = days / 7;
    days = days % 7;
  } else {
    week = 0;
  }

  // printf("%d \n", week);
  // printf("%d \n", days);
  //  Check if the hours input is valid
  if (hours < 0 || hours >= 24) {
    printf("Invalid hours.\n");
    return 1;
  }

  int week_charge;
  int day_charge;
  int four_hour_charge;
  int total_charge;
  // printf("%d \n", week_cost);
  week_charge = week * week_cost;
  day_charge = days * day_cost;
  if (hours <= 4) {
    four_hour_charge = four_hour;
  } else {
    four_hour_charge = day_cost;
  }
  if (day_charge >= week_cost) {
    day_charge = week_cost;
    four_hour_charge = 0;
  }
  total_charge = week_charge + day_charge + four_hour_charge;
  // printf("%d \n", week_charge);
  // printf("%d \n", day_charge);
  // printf("%d \n", four_hour_charge);
  printf("Charge($): %d", total_charge);
  return 0;
}