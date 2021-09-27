/*
Navicat MySQL Data Transfer

Source Server         : 本地连接
Source Server Version : 50722
Source Host           : localhost:3306
Source Database       : gnap

Target Server Type    : MYSQL
Target Server Version : 50722
File Encoding         : 65001

Date: 2020-11-30 22:55:37
*/

SET FOREIGN_KEY_CHECKS=0;

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
