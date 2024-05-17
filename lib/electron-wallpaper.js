// @ts-check

/*
 * Copyright 2018 Robin Andersson <me@robinwassen.com>
 * Copyright 2019 Zisu Zhang <admin@zhangzisu.cn>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @module electron-wallpaper
 */

'use strict'

import bindings from 'bindings';
const ewb = bindings('electron-wallpaper')

/**
 * @summary Attach a window as wallpaper
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window - Window to attach as wallpaper
 *
 * @example
 * const electronWallpaper = require('electron-wallpaper');
 * const currentWindow = require('electron').remote.getCurrentWindow();
 *
 * electronWallpaper.attachWindow(currentWindow);
 */
export const attachWindow = function attachWindow (window) {
  ewb.attachWindow(window.getNativeWindowHandle())
};

/**
 * @summary Detach a window
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window - Window to detach
 *
 * @example
 * const electronWallpaper = require('electron-wallpaper');
 * const currentWindow = require('electron').remote.getCurrentWindow();
 *
 * electronWallpaper.attachWindow(currentWindow);
 */
export const detachWindow = function detachWindow (window) {
  ewb.detachWindow(window.getNativeWindowHandle())
};

/**
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window
 * @param {number} accent
 * @param {number} tint
 */
function swca (window, accent, tint) {
  const handle = window.getNativeWindowHandle()
  if (!(handle instanceof Buffer)) {
    throw new Error('The \'window\' argument is not a native window handler.')
  }
  if (typeof tint !== 'number') {
    throw new Error('The \'tint\' argument is not a number.')
  }
  return ewb.setComposition(window.getNativeWindowHandle(), accent, tint)
}

/**
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window
 */
export const disable = function disable (window) {
  return swca(window, 0, 0x00000000)
};

/**
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window
 * @param {number} tint
 */
export const setGradient = function setGradient (window, tint) {
  return swca(window, 1, tint)
};

/**
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window
 * @param {number} tint
 */
export const setTransparentGradient = function setTransparentGradient (window, tint) {
  return swca(window, 2, tint)
};

/**
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window
 * @param {number} tint
 */
export const setBlurBehind = function setBlurBehind (window, tint) {
  return swca(window, 3, tint)
};

/**
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window
 * @param {number} tint
 */
export const setAcrylic = function setAcrylic (window, tint) {
  return swca(window, 4, tint)
};
