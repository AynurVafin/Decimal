#include "../s21_decimal.h"
int s21_is_less_or_equal(s21_decimal a, s21_decimal b) {
  if (s21_is_zero(a) && s21_is_zero(b)) return 1;
  if ((a.bits[3] >> 31) != (b.bits[3] >> 31)) return a.bits[3] >> 31;
  int scale_diff = (a.bits[3] >> 16 & 0xFF) - (b.bits[3] >> 16 & 0xFF);
  int flag = 0;
  if (scale_diff != 0) flag = s21_to_the_same_scale(&a, &b, scale_diff);
  if (flag) {
    if (a.bits[3] >> 31) return scale_diff < 0;
    return scale_diff > 0;
  }
  for (int i = 2; i >= 0; i--)
    if (a.bits[i] != b.bits[i]) {
      if (a.bits[3] >> 31) return a.bits[i] > b.bits[i];
      return a.bits[i] < b.bits[i];
    }
  return 1;
}
