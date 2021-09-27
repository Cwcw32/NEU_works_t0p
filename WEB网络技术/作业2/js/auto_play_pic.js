/* CSS Document */
$(function(){
/*图片轮换的js*/

/*********初始设置**************/

	/*获取节点对象*/
	var imgOuter = $('.wrap');//所有图片所处的容器
	var imgDiv = $('.pic');//各图片所在的div容器

/*	//设置部分初始值与计算*/
	var timeId = null;//记录如片轮换的定时器，自动轮换与鼠标控制切换时用到

	var edgeDistance = 91;//记录相邻图片错开的距离

	var imgNow = 0;//记录当前显示的第几张图片，此处为默认值0
	var imgMouse = 0;//记录鼠标停留在第几张图片上

	var imgOuterWidth = imgOuter.width();//记录所有图片最外层容器的宽度，计算即将显示第一张图片时的，其他图片移动的距离
/*// alert(imgDiv.size());*/
/**********方法*************/

	/*图片自动轮换的方法主体*/
	function autoSlide(){
		/*计算第几张图片开始运动*/
		if(imgNow == imgDiv.size()-1){
			imgNow = 0;
		}else{
			imgNow ++;
		}

		/*显示第一张图片和显示后面图片的移动方式不同*/
		if(imgNow == 0){/*显示第一张图片*/
			imgDiv.eq(imgNow).children().hide().siblings().children().show();			
			imgDiv.eq(imgNow).siblings().children().show();
			/*图片运动*/
			for(var i=imgDiv.size()-1;i>0;i--){
				imgDiv.eq(i).animate({'left':imgOuterWidth-(imgDiv.size()-i)*edgeDistance+'px'},700);
			}
		}else{/*显示第一张之外的任意图片*/
			imgDiv.eq(imgNow).children().hide().siblings().children().show();			
			imgDiv.eq(imgNow).siblings().children().show();
			/*图片运动*/
			imgDiv.eq(imgNow).animate({'left':edgeDistance*imgNow+'px'},700);
		}
	}

	/*鼠标影响图片轮换的方法主体*/
	function mouseSlide(){
		/*判断鼠标所在图片是否已轮换过，选择右边图片移动或左边图片移动*/
		if(imgMouse > imgNow){/*鼠标左边图片移动，即鼠标选中的是当前图片右边的图片*/
			for(var i= imgNow+1;i<=imgMouse;i++){
				imgDiv.eq(imgMouse).children().hide();
				imgDiv.eq(imgMouse).siblings().children().show();
				/*图片移动*/
				imgDiv.eq(i).stop().animate({'left':edgeDistance*i+'px'},700);
			}
			/*重置当前图片的索引*/
			imgNow = imgMouse;
		}else{//鼠标右边图片移动，即鼠标选中的是当前图片左边的图片
			for(var i= imgNow;i>imgMouse;i--){
				//图片左上角数字样式改变
				imgDiv.eq(imgMouse).children().hide();
				imgDiv.eq(imgMouse).siblings().children().show();
				//图片移动
				imgDiv.eq(i).stop().animate({'left':imgOuterWidth-(imgDiv.size()-i)*edgeDistance+'px'},700);
			}
			//重置当前图片的索引
			imgNow = imgMouse;
		}
	}

/**********图片控制事件*************/
	/*图片自动轮换*/
	timeId = setInterval(autoSlide,3000);
	/*鼠标影响图片轮换*/
	imgDiv.hover(function(){
		//鼠标移入，停止自动轮换
		clearInterval(timeId);
		//获得鼠标停留在第几张图片，调用鼠标事件的方法
		imgMouse = $(this).index();
		if(imgMouse != imgNow){
			mouseSlide();
		}		
	},function(){
		//鼠标离开，继续自动轮换
		timeId = setInterval(autoSlide,3000);
	}).bind('click',function(){
		imgNow = $(this).index();
	});
	
});
