# Course-Scheduling-System

基于遗传算法的排课系统

基于qt实现

面向中小学排课

------

硬约束：

1. 一个教师在同一时间段内只能安排一门课程；√

2. 一个班级在同一时间段内只能安排一门课程；√

   

软约束：

1. 时段限制，即横向时间段限制，格式：对象+时间段+形式+次数。其中对象可选项为【科目，教师】，时间段可选项为【节次、上午、下午】，形式可选项为【固定、最少、最多】，次数为【0、1、2、···】；

   数据库：xingzhi_schedule_rule_time_limit

2. 各天限制，即纵向时间段限制，格式：对象+时间段+形式+次数。其中对象可选项为【科目，教师】，时间段可选项为【每天、星期一、星期二、星期三、星期四、星期五】，形式可选项为【固定、最少、最多】，次数为【0、1、2、···】；

   数据库：xingzhi_schedule_rule_day_limit

3. 教师互斥，格式：教师A+教师B，A与B不同时上课；

   数据库：xingzhi_schedule_rule_teacher_limit

4. 科目互斥，格式：科目A+科目B，A与B不排在同一天；

   数据库：xingzhi_schedule_rule_subject_mutex

5. 科目相邻，格式：科目A+科目B，A与B在同一天相邻；

   数据库：xingzhi_schedule_subject_two

6. 禁止科目相邻，格式：科目A+科目B，A不排于B前面；

   数据库：xingzhi_schedule_rule_subject_adjacent

7. 科目预设，格式：年级+班级+科目+时间+限制，限制可选项为【一定排、尽量排、不排】；

   数据库：xingzhi_schedule_rule_subject_preset

8. 教师预设，格式：教师+时间+限制，限制可选项为【一定排、尽量排、不排】；

   数据库：xingzhi_schedule_rule_teacher_preset

