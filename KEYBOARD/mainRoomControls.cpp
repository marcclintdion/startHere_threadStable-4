
    if (keys[VK_LEFT])
    {
             moveSet[0]         +=  .101;
    }
    if (keys[VK_RIGHT])
    {
             moveSet[0]         -=  .101;
    }
    if (keys[VK_UP])
    {
             moveSet[1]         -=  .101;
    }
    if (keys[VK_DOWN])
    {
             moveSet[1]         +=  .101;
    } 
    if (keys[VK_PRIOR])
    {
             moveSet[2]         -=  .101;
    }
    if (keys[VK_NEXT])
    {
             moveSet[2]         +=  .101;
    }         
    
    if (keys[VK_LEFT]  && keys[VK_SHIFT])
    {
             moveSet[0]         +=  .2001;
    }
    if (keys[VK_RIGHT] && keys[VK_SHIFT])
    {
             moveSet[0]         -=  .2001;
    }
    if (keys[VK_UP]    && keys[VK_SHIFT])
    {
             moveSet[1]         -=  .2001;
    }
    if (keys[VK_DOWN]  && keys[VK_SHIFT])
    {
             moveSet[1]         +=  .2001;
    } 
    if (keys[VK_PRIOR] && keys[VK_SHIFT])
    {
             moveSet[2]         -=  .2001;
    }
    if (keys[VK_NEXT] && keys[VK_SHIFT])
    {
             moveSet[2]         +=  .2001;
    }         
    
    
    
   //=========================================================
    if (keys['L'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyePosition_SHADOW[0]         +=  1.001;
    }
    if (keys['J'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyePosition_SHADOW[0]         -=  1.001;
    }    
    if (keys['I'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyePosition_SHADOW[1]         +=  1.001;
    } 
    if (keys['K'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyePosition_SHADOW[1]         -=  1.001;
    }
    if (keys['O'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyePosition_SHADOW[2]         +=  1.001;
    }
    if (keys['U'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])  
    {
             eyePosition_SHADOW[2]         -=  1.001;
    }
    //-------------------------------------
    if (keys['H'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             spinShadow[0]        +=  .112;
    }
    if (keys['G'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])  
    {
             spinShadow[0]         -=  .112;
    } 
    //-------------------------------------
    if (keys['Y'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             spinShadow[1]        +=  .112;
    }
    if (keys['T'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])  
    {
             spinShadow[1]         -=  .112;
    }     
       
    //=====================================================
 
 
 
    //=========================================================
    if (keys['D'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyePosition[0]         +=  .3012;
    }
    if (keys['A'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyePosition[0]         -=  .3012;
    }    
    if (keys['W'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyePosition[1]         +=  .3012;
    } 
    if (keys['S'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyePosition[1]         -=  .3012;
    }
    if (keys['E'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             eyePosition[2]         +=  .3012;
    }
    if (keys['Q'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])  
    {
             eyePosition[2]         -=  .3012;
    }
    //===================================================== 
 
 
 
 
 
 
 
