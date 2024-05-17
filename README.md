<!-- Make sure you edit doc/README.hbs rather than README.md because the latter is auto-generated -->

electron-wallpaper-napi
=========

> Node module that allows you to attach a window as wallpaper in Windows.

[![npm](https://img.shields.io/npm/dw/electron-wallpaper.svg)](https://npmjs.com/package/electron-wallpaper)
[![NpmVersion](https://img.shields.io/npm/v/electron-wallpaper.svg)](https://npmjs.com/package/electron-wallpaper)
[![NpmLicense](https://img.shields.io/npm/l/electron-wallpaper.svg)](https://npmjs.com/package/electron-wallpaper)
[![AppVeyor branch](https://img.shields.io/appveyor/ci/robinwassen/electron-wallpaper/master.svg?logo=appveyor)](https://ci.appveyor.com/project/robinwassen/electron-wallpaper)
[![Travis (.org) branch](https://img.shields.io/travis/robinwassen/electron-wallpaper/master.svg?logo=travis)](https://travis-ci.org/robinwassen/electron-wallpaper)

*This module only supports Windows*

electron-wallpaper allows you to insert a Window between the wallpaper and the desktop icons in Windows. User input interaction with the window is not possible, therefore this module is suitable if you wish to build a desktop dashboard application such as [Rainmeter](https://rainmeter.net) but use Electron and NodeJS.

Example application
-------------

![Example application gif](./media/electron-wallpaper-example.gif)

An example application is located in the `/example/` dir, start it by running:

```sh
$ npm run example
```

Installation
------------

Install `electron-wallpaper` by running:

```sh
$ npm install --save electron-wallpaper
```

Native binaries for win, mac and linux are prebuilt and downloaded when the module is installed.

Documentation
-------------

<a name="module_electron-wallpaper.attachWindow"></a>

### electron-wallpaper.attachWindow(window)
**Kind**: static method of [<code>electron-wallpaper</code>](#module_electron-wallpaper)  
**Summary**: Attach a window as wallpaper  
**Access**: public  

| Param | Type | Description |
| --- | --- | --- |
| window | <code>BrowserWindow</code> | Window to attach as wallpaper |

**Example**  
```js
const electronWallpaper = require('electron-wallpaper');
const currentWindow = require('electron').remote.getCurrentWindow();

electronWallpaper.attachWindow(currentWindow);
```

Contribute
----------

Feel free to contribute to this module.

Before submitting a PR, please make sure that the linter runs without any warning:

```sh
$ npm run lint
```

License
-------

The project is licensed under the Apache 2.0 license.
