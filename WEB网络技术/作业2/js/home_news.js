$(document).ready(function(){
	//设计案例切换
	$('.new_telst li').mouseover(function(){
		var liindex = $('.new_telst li').index(this);
		$(this).addClass('newon').siblings().removeClass('newon');
		$('.new-wrap div.new_lst').eq(liindex).fadeIn(150).siblings('div.new_lst').hide();
		var liWidth = $('.new_telst li').width();
		$('.newtel .new_telst p').stop(false,true).animate({'left' : liindex * liWidth + 'px'},300);
	});
	
});