
      //===========================================================================================
      #ifdef __APPLE__
      //----------------
      spriteImage             = [UIImage imageNamed:@"o14.png"].CGImage ; 
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
              glGenTextures(1, &o14_COLORMAP);  
              glBindTexture(GL_TEXTURE_2D, o14_COLORMAP);   
      ConfigureAndLoadTexture(spriteData,  width, height); 
      if(spriteData != NULL) 
      { 
              free(spriteData); 
      } 

      //-----------------------------------------------------------------------------------------
/*      spriteImage             = [UIImage imageNamed:@"o14_DOT3.png"].CGImage ; 
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
              glGenTextures(1, &o14_NORMALMAP);  
              glBindTexture(GL_TEXTURE_2D, o14_NORMALMAP);   
      ConfigureAndLoadTexture(spriteData,  width, height); 
      if(spriteData != NULL) 
      { 
              free(spriteData); 
      } 

      //-------------------------------------------------------------------------------------------
      spriteImage             = [UIImage imageNamed:@"o14_MASK0.png"].CGImage ; 
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
              glGenTextures(1, &o14_MASK0MAP);  
              glBindTexture(GL_TEXTURE_2D, o14_MASK0MAP);   
      ConfigureAndLoadTexture(spriteData,  width, height); 
      if(spriteData != NULL) 
      { 
              free(spriteData); 
      }*/ 
      //---- 
      #endif 



      //=====================================================

load_o14_VBOs();  

      //=====================================================

      o14_boundingBox[0] = -19.569626f;   
      o14_boundingBox[1] =  21.197662f;  
      o14_boundingBox[2] = -17.195683f;   
      o14_boundingBox[3] =  17.354311f;  
      o14_boundingBox[4] = -3.106882f;   
      o14_boundingBox[5] =  7.685366f;  
