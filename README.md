# NinePatch - Demo Bug

All devices show button wrong.

If i keep only the below line in `AppDelegate.cpp`, it works:

```cpp
glView->setDesignResolutionSize(frameSize.width, frameSize.height, ResolutionPolicy::SHOW_ALL);
```

But when i set `setContentScaleFactor` nine patch images break.

## Screenshot

![Extras/images/ss.jpg](Extras/images/ss.jpg)
