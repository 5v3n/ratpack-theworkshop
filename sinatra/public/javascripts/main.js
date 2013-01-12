$(document).ready(function() {
  function poll(){
    setTimeout(function(){
      $.ajax({
      url: "status.json",
      dataType: "json",
      success: function(data){
        if(data.activated === 0){
          var button = $('.btn.on');
          button.removeClass('on');
          button.addClass('off');
          button.html('off')
        }
        else if(data.activated === 1){
          var button = $('.btn.off');
          button.removeClass('off');
          button.addClass('on'); 
          button.html('on')
        }
      },
      complete: poll,
    });
    }, 500)
  };
  poll();
});