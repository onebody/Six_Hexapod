
void control(int ctl_type) {
  switch (ctl_type) {
    case 0://初始状态
      ctl_init();
      break;
    case 1://前进
      ctl_forward();
      break;
    case 2://左转
      ctl_left();
      break;
    case 3://右转
      ctl_right();
      break;
    case 4://后退
      ctl_back();
      break;
    case 5://站立
      ctl_stand();
      break;
    case 6:// 蹲下
      ctl_down();
      break;
    case 7:// 把所有的脚抬起来
      ctl_LiftUpAll();
      break;
  }


  /*if (ctl_type == 0) {
    Serial.println("#0P2200T1000");//输入0是0号舵机运动
    delay(1000);
    Serial.println("#0P800T1000");
    delay(1000);
  }

  if (ctl_type == 5) {
    Serial.println("#16P800T1000");//输入1是1好舵机运动
    delay(1000);
    Serial.println("#16P2200T1000");
    delay(1000);
  }*/

}
