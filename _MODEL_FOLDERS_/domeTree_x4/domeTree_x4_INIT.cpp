
      //===========================================================================================
      #ifdef __APPLE__
      //-------------------------------------------------------------------------------------------
      spriteImage             = [UIImage imageNamed:@"domeTree_x4.png"].CGImage ; 
      width                   =  CGImageGetWidth(spriteImage); 
      height                  =  CGImageGetHeight(spriteImage);  
      spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));  
      spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);  
      CGContextSetBlendMode(spriteContext, kCGBlendModeCopy); 
      CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS 
      CGContextScaleCTM (spriteContext, 1.0, -1.0);           //--FLIP_Y_AXIS 
      CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);  
      CGContextRelease(spriteContext); 
      //--------- 
              glGenTextures(1, &domeTree_x4_COLORMAP);  
              glBindTexture(GL_TEXTURE_2D, domeTree_x4_COLORMAP);   
      ConfigureAndLoadTexture(spriteData,  width, height); 
      if(spriteData != NULL) 
      { 
              free(spriteData); 
      } 

      //-------------------------------------------------------------------------------------------
      #endif 



      //=====================================================

load_domeTree_x4_VBOs();  

      //=====================================================

      domeTree_x4_boundingBox[0] = -0.469588f;   
      domeTree_x4_boundingBox[1] =  0.717426f;  
      domeTree_x4_boundingBox[2] = -0.574330f;   
      domeTree_x4_boundingBox[3] =  0.554017f;  
      domeTree_x4_boundingBox[4] = 0.000000f;   
      domeTree_x4_boundingBox[5] =  1.000405f;  

