### extrabar

Add an extra bar on the other side of the primary bar, shows additional status sections.
_Requires_ `bar` patch to be applied first. Heavily inspired by `dwm`'s extrabar patch.

### Status

The status text on the extra bar is set using the stdin as usual, with the text being split by `;`

For example, if `status1;status2;status3` was set,
then `status1` is set as the status of the primary bar,
 `status2` is set as the left status of extrabar,
 `status3` is set as the right status of extrabar.

### Author

[dhruva_sambrani](/dhruva_sambrani)
