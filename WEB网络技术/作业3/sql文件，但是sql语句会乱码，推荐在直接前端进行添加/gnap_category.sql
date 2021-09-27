/*
Navicat MySQL Data Transfer

Source Server         : 本地连接
Source Server Version : 50722
Source Host           : localhost:3306
Source Database       : gnap

Target Server Type    : MYSQL
Target Server Version : 50722
File Encoding         : 65001

Date: 2020-11-30 22:55:40
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `gnap_category`
-- ----------------------------
DROP TABLE IF EXISTS `gnap_category`;
CREATE TABLE `gnap_category` (
  `CATE_ID` int(10) NOT NULL AUTO_INCREMENT,
  `CATE_NAME` varchar(20) NOT NULL,
  `CATE_PARENT_ID` decimal(10,0) NOT NULL,
  PRIMARY KEY (`CATE_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=38 DEFAULT CHARSET=utf8;


