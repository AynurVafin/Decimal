#include "../s21_decimal.h"
int s21_to_the_same_scale(s21_decimal *a, s21_decimal *b, int scale_diff) {
  s21_decimal temp = {0};
  s21_decimal res = {0};
  int flag = 0;
  s21_from_float_to_decimal(pow(10, abs(scale_diff)), &temp);
  if (scale_diff < 0) {
    flag = s21_mul(*a, temp, &res);
    res.bits[3] = a->bits[3] + (abs(scale_diff) << 16);
    if (!flag)
      for (int i = 0; i <= 3; i++) a->bits[i] = res.bits[i];
  } else {
    flag = s21_mul(*b, temp, &res);
    res.bits[3] = b->bits[3] + (abs(scale_diff) << 16);
    if (!flag)
      for (int i = 0; i <= 3; i++) b->bits[i] = res.bits[i];
  }
  return flag;
}