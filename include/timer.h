#include <libmaple/timer.h>

#define TIMER_MAX 65535
#define CYCLES_PER_MICROSECOND 72 //Assuming 72MHz clock. Change accordingly.

void set_timer_period(timer_dev * dev, uint32 us/* period in microseconds*/){
  uint32 pc = us*CYCLES_PER_MICROSECOND;
  uint16 ps = (uint16)(pc/TIMER_MAX + 1);
  uint16 ts = (uint16)((pc + ps/2) / ps);
  timer_set_prescaler(dev, ps - 1);
  timer_set_reload(dev, ts);
}
