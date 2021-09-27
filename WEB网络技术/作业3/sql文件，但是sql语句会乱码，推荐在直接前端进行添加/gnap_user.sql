/*
Navicat MySQL Data Transfer

Source Server         : 本地连接
Source Server Version : 50722
Source Host           : localhost:3306
Source Database       : gnap

Target Server Type    : MYSQL
Target Server Version : 50722
File Encoding         : 65001

Date: 2020-11-30 22:55:33
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `gnap_user`
-- ----------------------------
DROP TABLE IF EXISTS `gnap_user`;
CREATE TABLE `gnap_user` (
  `USER_ID` varchar(32) NOT NULL,
  `USER_NAME` varchar(20) NOT NULL,
  `USER_PASSWORD` varchar(20) NOT NULL,
  `USER_SEX` varchar(1) NOT NULL,
  `USER_BIRTHDAY` datetime DEFAULT NULL,
  `USER_IDENITY_CODE` varchar(60) DEFAULT NULL,
  `USER_EMAIL` varchar(60) DEFAULT NULL,
  `USER_MOBILE` varchar(11) DEFAULT NULL,
  `USER_ADDRESS` varchar(200) NOT NULL,
  `USER_STATUS` decimal(6,0) NOT NULL,
  PRIMARY KEY (`USER_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of gnap_user
-- ----------------------------
INSERT INTO `gnap_user` VALUES ('admin', 'Shiyin Ling', '1', 'T', '2019-10-18 00:00:00', null, '294594605@qq.com', '18640666836', '无', '1');
INSERT INTO `gnap_user` VALUES ('admin1', 'admin', '123', 'T', '2019-10-08 00:00:00', null, 'aaa@bbb.com', '222222', '4323323232323232', '2');
INSERT INTO `gnap_user` VALUES ('admin2', 'admin', '123', 'T', '2019-10-08 00:00:00', null, 'aaa@bbb.com', '222222', '4323323232323232', '2');
INSERT INTO `gnap_user` VALUES ('admin3', 'admin', '123', 'T', '2019-10-08 00:00:00', null, 'aaa@bbb.com', '222222', '4323323232323232', '2');
INSERT INTO `gnap_user` VALUES ('admin4', 'admin', '123', 'T', '2019-10-08 00:00:00', null, 'aaa@bbb.com', '222222', '4323323232323232', '2');
INSERT INTO `gnap_user` VALUES ('admin5', 'admin', '123', 'T', '2019-10-08 00:00:00', null, 'aaa@bbb.com', '222222', '4323323232323232', '2');
INSERT INTO `gnap_user` VALUES ('admin6', 'admin', '123', 'T', '2019-10-08 00:00:00', null, 'aaa@bbb.com', '222222', '4323323232323232', '2');
INSERT INTO `gnap_user` VALUES ('admin7', 'admin', '123', 'T', '2019-10-08 00:00:00', null, 'aaa@bbb.com', '222222', '4323323232323232', '2');
INSERT INTO `gnap_user` VALUES ('hello123', 'hello2fasfafas', '111', 'T', '2019-10-15 00:00:00', null, 'aaa@lmonkey.com', '121212121', '', '1');
INSERT INTO `gnap_user` VALUES ('hello2', 'hello', '111', 'F', '2019-10-08 00:00:00', null, '88888', '88888', '8888888888', '1');
INSERT INTO `gnap_user` VALUES ('hello3', 'rewreww', 'www', 'T', '2019-10-08 00:00:00', null, 'retrewtrew', 'trewtrewt', 'rewtrewtew', '1');
