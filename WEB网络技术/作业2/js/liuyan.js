	$(".customer-comment .content").slide({
		titCell: ".hd ul li",
		mainCell: ".bd ul",
		effect: "leftLoop",//加载方式
		autoPlay: true,//自动播放
		prevCell: '.prev',//左右前进后退
		nextCell: '.next',
		titOnClassName: 'active',
		mouseOverStop: true,
		interTime: 5000//毫秒间隔
	});