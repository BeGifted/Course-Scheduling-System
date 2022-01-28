/*
 Navicat Premium Data Transfer

 Source Server         : localhost
 Source Server Type    : MySQL
 Source Server Version : 50721
 Source Host           : localhost:3306
 Source Schema         : schedule

 Target Server Type    : MySQL
 Target Server Version : 50721
 File Encoding         : 65001

 Date: 21/01/2022 17:31:59
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for xingzhi_schedule_period
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_period`;
CREATE TABLE `xingzhi_schedule_period`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_schedule_rule_daylimit
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_rule_daylimit`;
CREATE TABLE `xingzhi_schedule_rule_daylimit`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_schedule_rule_subject_adjacent
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_rule_subject_adjacent`;
CREATE TABLE `xingzhi_schedule_rule_subject_adjacent`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_schedule_rule_subject_mutex
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_rule_subject_mutex`;
CREATE TABLE `xingzhi_schedule_rule_subject_mutex`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_schedule_rule_subject_preset
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_rule_subject_preset`;
CREATE TABLE `xingzhi_schedule_rule_subject_preset`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_schedule_rule_teacher_limit
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_rule_teacher_limit`;
CREATE TABLE `xingzhi_schedule_rule_teacher_limit`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_schedule_rule_teacher_preset
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_rule_teacher_preset`;
CREATE TABLE `xingzhi_schedule_rule_teacher_preset`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_schedule_rule_time_limit
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_rule_time_limit`;
CREATE TABLE `xingzhi_schedule_rule_time_limit`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_schedule_rules
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_rules`;
CREATE TABLE `xingzhi_schedule_rules`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_schedule_subject
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_subject`;
CREATE TABLE `xingzhi_schedule_subject`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_schedule_subject_time
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_subject_time`;
CREATE TABLE `xingzhi_schedule_subject_time`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_schedule_subject_two
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_subject_two`;
CREATE TABLE `xingzhi_schedule_subject_two`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_schedule_teacher
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_schedule_teacher`;
CREATE TABLE `xingzhi_schedule_teacher`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid'
) ENGINE = MyISAM CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for xingzhi_wechat_class
-- ----------------------------
DROP TABLE IF EXISTS `xingzhi_wechat_class`;
CREATE TABLE `xingzhi_wechat_class`  (
  `id` smallint(5) NOT NULL COMMENT '部门ID',
  `name` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL COMMENT '门部名称',
  `parent_id` smallint(5) NULL DEFAULT NULL COMMENT '父部门ID',
  `type` tinyint(1) NULL DEFAULT NULL COMMENT '部门类型',
  `type_name` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL COMMENT '部门类型名称',
  `register_year` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL COMMENT '入学年份',
  `standard_grade` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL COMMENT '标准年级',
  `order` int(11) NULL DEFAULT NULL COMMENT '序码排',
  `open_group_chat` tinyint(1) NULL DEFAULT NULL COMMENT '否是开启班级群',
  `company_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '单位UUID',
  `create_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人account',
  `create_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人Realname',
  `create_date` datetime(0) NULL DEFAULT NULL,
  `edit_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人uuid',
  `edit_by_account` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人account',
  `edit_by_name` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '编辑人Realname',
  `edit_date` datetime(0) NULL DEFAULT NULL,
  `is_delete` enum('0','1') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0' COMMENT '1表示已删除',
  `delete_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `delete_date` datetime(0) NULL DEFAULT NULL,
  `create_by_uuid` varchar(1000) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '创建人uuid',
  `teacher_num` int(11) NOT NULL DEFAULT 0 COMMENT '教师数',
  `student_num` int(11) NOT NULL DEFAULT 0 COMMENT '学生数',
  `department_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL COMMENT '班级名称，如：初一1班',
  `path` varchar(1000) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL COMMENT '路径',
  `jck_match` tinyint(1) NULL DEFAULT 1 COMMENT '是否跟基础库匹配',
  `campus_class_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL COMMENT '带上校区后的班级名称',
  UNIQUE INDEX `idx_id`(`id`, `company_uuid`) USING BTREE,
  INDEX `idx_name`(`department_name`) USING BTREE,
  INDEX `campus_class_name`(`campus_class_name`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
