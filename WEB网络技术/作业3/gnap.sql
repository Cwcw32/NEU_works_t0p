/*
Navicat MySQL Data Transfer

Source Server         : 本地连接
Source Server Version : 50722
Source Host           : localhost:3306
Source Database       : gnap

Target Server Type    : MYSQL
Target Server Version : 50722
File Encoding         : 65001

Date: 2020-11-30 23:29:06
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `gnap_cart`
-- ----------------------------
DROP TABLE IF EXISTS `gnap_cart`;
CREATE TABLE `gnap_cart` (
  `cart_id` int(11) NOT NULL AUTO_INCREMENT,
  `cart_p_filename` varchar(128) DEFAULT NULL,
  `cart_p_name` varchar(64) DEFAULT NULL,
  `cart_p_price` decimal(10,2) DEFAULT NULL,
  `cart_quantity` int(11) DEFAULT NULL,
  `cart_p_stock` int(11) DEFAULT NULL,
  `cart_p_id` int(11) DEFAULT NULL,
  `cart_u_id` varchar(64) DEFAULT NULL,
  `cart_valid` int(11) DEFAULT NULL,
  PRIMARY KEY (`cart_id`)
) ENGINE=InnoDB AUTO_INCREMENT=27 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of gnap_cart
-- ----------------------------
-- ----------------------------
-- Table structure for `gnap_category`
-- ----------------------------
DROP TABLE IF EXISTS `gnap_category`;
CREATE TABLE `gnap_category` (
  `CATE_ID` int(10) NOT NULL AUTO_INCREMENT,
  `CATE_NAME` varchar(20) NOT NULL,
  `CATE_PARENT_ID` decimal(10,0) NOT NULL,
  PRIMARY KEY (`CATE_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=52 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of gnap_category
-- ----------------------------
INSERT INTO `gnap_category` VALUES ('39', '蔬菜', '38');
INSERT INTO `gnap_category` VALUES ('40', '水果', '38');
INSERT INTO `gnap_category` VALUES ('42', '蔬菜', '41');
INSERT INTO `gnap_category` VALUES ('43', '水果', '41');
INSERT INTO `gnap_category` VALUES ('45', 'GREEN', '0');
INSERT INTO `gnap_category` VALUES ('46', 'VEGE', '45');
INSERT INTO `gnap_category` VALUES ('47', 'FRU', '45');
INSERT INTO `gnap_category` VALUES ('48', 'PRO', '0');
INSERT INTO `gnap_category` VALUES ('49', 'HUANBAO', '48');
INSERT INTO `gnap_category` VALUES ('50', 'GONGYE', '48');
INSERT INTO `gnap_category` VALUES ('51', 'SHOUGONG', '48');

-- ----------------------------
-- Table structure for `gnap_product`
-- ----------------------------
DROP TABLE IF EXISTS `gnap_product`;
CREATE TABLE `gnap_product` (
  `PRODUCT_ID` int(10) NOT NULL AUTO_INCREMENT,
  `PRODUCT_NAME` varchar(128) NOT NULL,
  `PRODUCT_DESCRIPTION` varchar(512) DEFAULT NULL,
  `PRODUCT_PRICE` decimal(10,2) NOT NULL,
  `PRODUCT_STOCK` decimal(10,0) DEFAULT NULL,
  `PRODUCT_FID` decimal(10,0) DEFAULT NULL,
  `PRODUCT_CID` decimal(10,0) DEFAULT NULL,
  `PRODUCT_FILENAME` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`PRODUCT_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=35 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of gnap_product
-- ----------------------------

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
