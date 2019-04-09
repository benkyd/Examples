=IF(D38 > 13,"N/A",HYPERLINK("https://docs.google.com/forms/d/e/1FAIpQLSfpA5SJ3sAUMZMqdOP2ZAeFbkxosCvwMgdG6rrst5dFMydbwA/viewform?usp=pp_url&entry.242009976="&$C$4&"&entry.1436619179="&$C$5&"&entry.972555158=PCSO&entry.1262374836=Practical+Assessment&entry.282814154=Failed&entry.5325104="&LEFT(getSheetUrl(),84)&"&entry.160193935="&$F$5&"&entry.2111787394="&LEFT($F$5,10)&"&entry.171317265="&"Failed theory side of the Practical Assesment"&"","Master Form"))

=IF(D38 > 13,
    "N/A",
    HYPERLINK("https://docs.google.com/forms/d/e/1FAIpQLSfpA5SJ3sAUMZMqdOP2ZAeFbkxosCvwMgdG6rrst5dFMydbwA/viewform?usp=pp_url
        &entry.242009976="&$C$4&"
        &entry.1436619179="&$C$5&"
        &entry.972555158=PCSO
        &entry.1262374836=Practical+Assessment
        &entry.282814154=Failed
        &entry.5325104="&LEFT(getSheetUrl(),84)&"
        &entry.160193935="&$F$5&"
        &entry.2111787394="&LEFT($F$5,10)&"
        &entry.171317265="&"Failed theory side of the Practical Assesment"&"","Master Form"))



=IF(D19 > 3,"N/A", HYPERLINK("https://docs.google.com/forms/d/e/1FAIpQLSfpA5SJ3sAUMZMqdOP2ZAeFbkxosCvwMgdG6rrst5dFMydbwA/viewform?usp=pp_url&entry.242009976="&$C$4&"&entry.1436619179="&$C$5&"&entry.972555158=CSO&entry.1262374836=Trainee+Module&entry.282814154=Failed&entry.5325104="&LEFT(getSheetUrl(),84)&"&entry.160193935="&$F$5&"&entry.2111787394="&LEFT($F$5,10)&"&entry.171317265="&"Failed theory side of the Trainee Module"&"","Master Form"))

=IF(D19 < 3,
    "N/A",
    HYPERLINK("https://docs.google.com/forms/d/e/1FAIpQLSfpA5SJ3sAUMZMqdOP2ZAeFbkxosCvwMgdG6rrst5dFMydbwA/viewform?usp=pp_url
        &entry.242009976="&$C$4&"
        &entry.1436619179="&$C$5&"
        &entry.972555158=CSO
        &entry.1262374836=Trainee+Module
        &entry.282814154=Failed
        &entry.5325104="&LEFT(getSheetUrl(),84)&"
        &entry.160193935="&$F$5&"
        &entry.2111787394="&LEFT($F$5,10)&"
        &entry.171317265="&"Failed theory side of the Trainee Module"&"","Master Form"))



=HYPERLINK("https://docs.google.com/forms/d/e/1FAIpQLSfpA5SJ3sAUMZMqdOP2ZAeFbkxosCvwMgdG6rrst5dFMydbwA/viewform?usp=pp_url&entry.242009976="&$C$4&"&entry.1436619179="&$C$5&"&entry.972555158="&IF($E33>41,"CSO","N/A")&"&entry.1262374836=Interview&entry.282814154="&IF($E33>41,"Passed","Failed")&"&entry.5325104="&LEFT(getSheetUrl(),84)&"&entry.160193935="&$F$5&"&entry.2111787394="&$F$4&"&entry.171317265","Master Form")

=HYPERLINK("https://docs.google.com/forms/d/e/1FAIpQLSfpA5SJ3sAUMZMqdOP2ZAeFbkxosCvwMgdG6rrst5dFMydbwA/viewform?usp=pp_url
    &entry.242009976="&$C$4&"
    &entry.1436619179="&$C$5&"
    &entry.972555158="&IF($E33>41,N/A,CSO)&"
    &entry.1262374836=Interview
    &entry.282814154="&IF($E33>41,"Passed","Failed")&"
    &entry.5325104="&LEFT(getSheetUrl(),84)&"
    &entry.160193935="&$F$5&"
    &entry.2111787394="&$F$4&"&entry.171317265","Master Form")



=IF($E33>=42,HYPERLINK("https://docs.google.com/forms/d/e/1FAIpQLSfYYhp0nG-17ZnNy7pI379V8Shcf21zjon535Y5LxLdie1IhA/viewform?entry.603263027="&$F$5&"&entry.281191701="&$C$4&"&entry.515816008="&$C$5&"&entry.1181448375="&$C$6&"&entry.1135135300=Trainee&entry.685851489=None&entry.385608648=CSO&entry.1761605268=New Trainee&entry.790485595="&$C$6&"","WHITELISTING FORM"),"WHITELISTING N/A")

=IF($E33>=42,HYPERLINK("https://docs.google.com/forms/d/e/1FAIpQLSfYYhp0nG-17ZnNy7pI379V8Shcf21zjon535Y5LxLdie1IhA/viewform
    ?entry.603263027="&$F$5&"
    &entry.281191701="&$C$4&"
    &entry.515816008="&$C$5&"
    &entry.1181448375="&$C$6&"
    &entry.1135135300=Trainee
    &entry.685851489=None
    &entry.385608648=CSO
    &entry.1761605268=New Trainee
    &entry.790485595="&$C$6&"","WHITELISTING FORM"),"WHITELISTING N/A")


    
=IF($E33>=42,HYPERLINK("https://docs.google.com/document/d/144AvGvQdAiOjdTd6CG_ovL9W3vLRVNhw7BzLW3vsNLs/edit","Interview Brief"),"Interview Brief N/A")
