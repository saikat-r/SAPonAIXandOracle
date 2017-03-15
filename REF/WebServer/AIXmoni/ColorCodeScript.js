$(function() {
    $( "td" ).each(function(index) {
        var scale1 = [['IDEALlow', 100, 71], ['IDEALhigh', 69, 0], ['USElow', 69, 0], ['USEhigh', 100, 71], ['SoSo', 60, 70]];
        var scale2 = [['OK', "OK.", "NOT OK."]];
        var score1 = $(this).text();
        var score2 = $(this).text();
        var column 
                for (var i = 0; i < scale.length; i++)
                 {    

                    if (score1 <= scale[i][1]) {
                        $(this).addClass(scale[i][0]);
                    }
                    if (score2 <= scale[i][1]) {
                        $(this).addClass(scale[i][0]);
                    }
                }
                
            });
       });