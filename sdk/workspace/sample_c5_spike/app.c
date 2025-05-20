#include "app.h"
#include <stdio.h>
#include "LineTracer.h"

#include "spike/pup/forcesensor.h"

/* センサーポートの定義 */
static const pbio_port_id_t
  color_sensor_port    = PBIO_PORT_ID_E,
  left_motor_port      = PBIO_PORT_ID_B,
  right_motor_port     = PBIO_PORT_ID_A,
  force_sensor_port    = PBIO_PORT_ID_D;

/* メインタスク(起動時にのみ関数コールされる) */
void main_task(intptr_t unused) {
  printf("+---------------------------------+\n");
  printf("|   Press force sensor to start   |\n");
  printf("+---------------------------------+\n");
  /* フォースセンサーが押下されるまで待機 */
  pup_device_t *force_sensor = pup_force_sensor_get_device(force_sensor_port);
  while (!pup_force_sensor_touched(force_sensor)) {
    dly_tsk(10*1000);
  }

  /* LineTracerに構成を渡す */
  LineTracer_Configure(left_motor_port,right_motor_port,color_sensor_port);
  printf("Start Line Trace!!\n");
    
  /* ライントレースタスクの起動 */
  sta_cyc(LINE_TRACER_TASK_CYC);

  /* タスク終了 */
  ext_tsk();
}
