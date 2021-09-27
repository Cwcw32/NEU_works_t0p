/*
Navicat MySQL Data Transfer

Source Server         : 本地连接
Source Server Version : 50722
Source Host           : localhost:3306
Source Database       : gnap

Target Server Type    : MYSQL
Target Server Version : 50722
File Encoding         : 65001

Date: 2020-11-30 22:55:26
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
