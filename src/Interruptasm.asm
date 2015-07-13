global ISRWrapper
align 4

DefaultInterruptWrapper:
	pushad
	extern InterruptHandler
	call InterruptHandler
	popad
	add esp, 4
	; extern SayHello
	; call SayHello
	iret
	
global InterruptWrapper0
InterruptWrapper0:
	push 0
	jmp DefaultInterruptWrapper
global InterruptWrapper1
InterruptWrapper1:
	push 1
	jmp DefaultInterruptWrapper
global InterruptWrapper2
InterruptWrapper2:
	push 2
	jmp DefaultInterruptWrapper
global InterruptWrapper3
InterruptWrapper3:
	push 3
	jmp DefaultInterruptWrapper
global InterruptWrapper4
InterruptWrapper4:
	push 4
	jmp DefaultInterruptWrapper
global InterruptWrapper5
InterruptWrapper5:
	push 5
	jmp DefaultInterruptWrapper
global InterruptWrapper6
InterruptWrapper6:
	push 6
	jmp DefaultInterruptWrapper
global InterruptWrapper7
InterruptWrapper7:
	push 7
	jmp DefaultInterruptWrapper
global InterruptWrapper8
InterruptWrapper8:
	push 8
	jmp DefaultInterruptWrapper
global InterruptWrapper9
InterruptWrapper9:
	push 9
	jmp DefaultInterruptWrapper
global InterruptWrapper10
InterruptWrapper10:
	push 10
	jmp DefaultInterruptWrapper
global InterruptWrapper11
InterruptWrapper11:
	push 11
	jmp DefaultInterruptWrapper
global InterruptWrapper12
InterruptWrapper12:
	push 12
	jmp DefaultInterruptWrapper
global InterruptWrapper13
InterruptWrapper13:
	push 13
	jmp DefaultInterruptWrapper
global InterruptWrapper14
InterruptWrapper14:
	push 14
	jmp DefaultInterruptWrapper
global InterruptWrapper15
InterruptWrapper15:
	push 15
	jmp DefaultInterruptWrapper
global InterruptWrapper16
InterruptWrapper16:
	push 16
	jmp DefaultInterruptWrapper
global InterruptWrapper17
InterruptWrapper17:
	push 17
	jmp DefaultInterruptWrapper
global InterruptWrapper18
InterruptWrapper18:
	push 18
	jmp DefaultInterruptWrapper
global InterruptWrapper19
InterruptWrapper19:
	push 19
	jmp DefaultInterruptWrapper
global InterruptWrapper20
InterruptWrapper20:
	push 20
	jmp DefaultInterruptWrapper
global InterruptWrapper21
InterruptWrapper21:
	push 21
	jmp DefaultInterruptWrapper
global InterruptWrapper22
InterruptWrapper22:
	push 22
	jmp DefaultInterruptWrapper
global InterruptWrapper23
InterruptWrapper23:
	push 23
	jmp DefaultInterruptWrapper
global InterruptWrapper24
InterruptWrapper24:
	push 24
	jmp DefaultInterruptWrapper
global InterruptWrapper25
InterruptWrapper25:
	push 25
	jmp DefaultInterruptWrapper
global InterruptWrapper26
InterruptWrapper26:
	push 26
	jmp DefaultInterruptWrapper
global InterruptWrapper27
InterruptWrapper27:
	push 27
	jmp DefaultInterruptWrapper
global InterruptWrapper28
InterruptWrapper28:
	push 28
	jmp DefaultInterruptWrapper
global InterruptWrapper29
InterruptWrapper29:
	push 29
	jmp DefaultInterruptWrapper
global InterruptWrapper30
InterruptWrapper30:
	push 30
	jmp DefaultInterruptWrapper
global InterruptWrapper31
InterruptWrapper31:
	push 31
	jmp DefaultInterruptWrapper
global InterruptWrapper32
InterruptWrapper32:
	push 32
	jmp DefaultInterruptWrapper
global InterruptWrapper33
InterruptWrapper33:
	push 33
	jmp DefaultInterruptWrapper
global InterruptWrapper34
InterruptWrapper34:
	push 34
	jmp DefaultInterruptWrapper
global InterruptWrapper35
InterruptWrapper35:
	push 35
	jmp DefaultInterruptWrapper
global InterruptWrapper36
InterruptWrapper36:
	push 36
	jmp DefaultInterruptWrapper
global InterruptWrapper37
InterruptWrapper37:
	push 37
	jmp DefaultInterruptWrapper
global InterruptWrapper38
InterruptWrapper38:
	push 38
	jmp DefaultInterruptWrapper
global InterruptWrapper39
InterruptWrapper39:
	push 39
	jmp DefaultInterruptWrapper
global InterruptWrapper40
InterruptWrapper40:
	push 40
	jmp DefaultInterruptWrapper
global InterruptWrapper41
InterruptWrapper41:
	push 41
	jmp DefaultInterruptWrapper
global InterruptWrapper42
InterruptWrapper42:
	push 42
	jmp DefaultInterruptWrapper
global InterruptWrapper43
InterruptWrapper43:
	push 43
	jmp DefaultInterruptWrapper
global InterruptWrapper44
InterruptWrapper44:
	push 44
	jmp DefaultInterruptWrapper
global InterruptWrapper45
InterruptWrapper45:
	push 45
	jmp DefaultInterruptWrapper
global InterruptWrapper46
InterruptWrapper46:
	push 46
	jmp DefaultInterruptWrapper
global InterruptWrapper47
InterruptWrapper47:
	push 47
	jmp DefaultInterruptWrapper
global InterruptWrapper48
InterruptWrapper48:
	push 48
	jmp DefaultInterruptWrapper
global InterruptWrapper49
InterruptWrapper49:
	push 49
	jmp DefaultInterruptWrapper
global InterruptWrapper50
InterruptWrapper50:
	push 50
	jmp DefaultInterruptWrapper
global InterruptWrapper51
InterruptWrapper51:
	push 51
	jmp DefaultInterruptWrapper
global InterruptWrapper52
InterruptWrapper52:
	push 52
	jmp DefaultInterruptWrapper
global InterruptWrapper53
InterruptWrapper53:
	push 53
	jmp DefaultInterruptWrapper
global InterruptWrapper54
InterruptWrapper54:
	push 54
	jmp DefaultInterruptWrapper
global InterruptWrapper55
InterruptWrapper55:
	push 55
	jmp DefaultInterruptWrapper
global InterruptWrapper56
InterruptWrapper56:
	push 56
	jmp DefaultInterruptWrapper
global InterruptWrapper57
InterruptWrapper57:
	push 57
	jmp DefaultInterruptWrapper
global InterruptWrapper58
InterruptWrapper58:
	push 58
	jmp DefaultInterruptWrapper
global InterruptWrapper59
InterruptWrapper59:
	push 59
	jmp DefaultInterruptWrapper
global InterruptWrapper60
InterruptWrapper60:
	push 60
	jmp DefaultInterruptWrapper
global InterruptWrapper61
InterruptWrapper61:
	push 61
	jmp DefaultInterruptWrapper
global InterruptWrapper62
InterruptWrapper62:
	push 62
	jmp DefaultInterruptWrapper
global InterruptWrapper63
InterruptWrapper63:
	push 63
	jmp DefaultInterruptWrapper
global InterruptWrapper64
InterruptWrapper64:
	push 64
	jmp DefaultInterruptWrapper
global InterruptWrapper65
InterruptWrapper65:
	push 65
	jmp DefaultInterruptWrapper
global InterruptWrapper66
InterruptWrapper66:
	push 66
	jmp DefaultInterruptWrapper
global InterruptWrapper67
InterruptWrapper67:
	push 67
	jmp DefaultInterruptWrapper
global InterruptWrapper68
InterruptWrapper68:
	push 68
	jmp DefaultInterruptWrapper
global InterruptWrapper69
InterruptWrapper69:
	push 69
	jmp DefaultInterruptWrapper
global InterruptWrapper70
InterruptWrapper70:
	push 70
	jmp DefaultInterruptWrapper
global InterruptWrapper71
InterruptWrapper71:
	push 71
	jmp DefaultInterruptWrapper
global InterruptWrapper72
InterruptWrapper72:
	push 72
	jmp DefaultInterruptWrapper
global InterruptWrapper73
InterruptWrapper73:
	push 73
	jmp DefaultInterruptWrapper
global InterruptWrapper74
InterruptWrapper74:
	push 74
	jmp DefaultInterruptWrapper
global InterruptWrapper75
InterruptWrapper75:
	push 75
	jmp DefaultInterruptWrapper
global InterruptWrapper76
InterruptWrapper76:
	push 76
	jmp DefaultInterruptWrapper
global InterruptWrapper77
InterruptWrapper77:
	push 77
	jmp DefaultInterruptWrapper
global InterruptWrapper78
InterruptWrapper78:
	push 78
	jmp DefaultInterruptWrapper
global InterruptWrapper79
InterruptWrapper79:
	push 79
	jmp DefaultInterruptWrapper
global InterruptWrapper80
InterruptWrapper80:
	push 80
	jmp DefaultInterruptWrapper
global InterruptWrapper81
InterruptWrapper81:
	push 81
	jmp DefaultInterruptWrapper
global InterruptWrapper82
InterruptWrapper82:
	push 82
	jmp DefaultInterruptWrapper
global InterruptWrapper83
InterruptWrapper83:
	push 83
	jmp DefaultInterruptWrapper
global InterruptWrapper84
InterruptWrapper84:
	push 84
	jmp DefaultInterruptWrapper
global InterruptWrapper85
InterruptWrapper85:
	push 85
	jmp DefaultInterruptWrapper
global InterruptWrapper86
InterruptWrapper86:
	push 86
	jmp DefaultInterruptWrapper
global InterruptWrapper87
InterruptWrapper87:
	push 87
	jmp DefaultInterruptWrapper
global InterruptWrapper88
InterruptWrapper88:
	push 88
	jmp DefaultInterruptWrapper
global InterruptWrapper89
InterruptWrapper89:
	push 89
	jmp DefaultInterruptWrapper
global InterruptWrapper90
InterruptWrapper90:
	push 90
	jmp DefaultInterruptWrapper
global InterruptWrapper91
InterruptWrapper91:
	push 91
	jmp DefaultInterruptWrapper
global InterruptWrapper92
InterruptWrapper92:
	push 92
	jmp DefaultInterruptWrapper
global InterruptWrapper93
InterruptWrapper93:
	push 93
	jmp DefaultInterruptWrapper
global InterruptWrapper94
InterruptWrapper94:
	push 94
	jmp DefaultInterruptWrapper
global InterruptWrapper95
InterruptWrapper95:
	push 95
	jmp DefaultInterruptWrapper
global InterruptWrapper96
InterruptWrapper96:
	push 96
	jmp DefaultInterruptWrapper
global InterruptWrapper97
InterruptWrapper97:
	push 97
	jmp DefaultInterruptWrapper
global InterruptWrapper98
InterruptWrapper98:
	push 98
	jmp DefaultInterruptWrapper
global InterruptWrapper99
InterruptWrapper99:
	push 99
	jmp DefaultInterruptWrapper
global InterruptWrapper100
InterruptWrapper100:
	push 100
	jmp DefaultInterruptWrapper
global InterruptWrapper101
InterruptWrapper101:
	push 101
	jmp DefaultInterruptWrapper
global InterruptWrapper102
InterruptWrapper102:
	push 102
	jmp DefaultInterruptWrapper
global InterruptWrapper103
InterruptWrapper103:
	push 103
	jmp DefaultInterruptWrapper
global InterruptWrapper104
InterruptWrapper104:
	push 104
	jmp DefaultInterruptWrapper
global InterruptWrapper105
InterruptWrapper105:
	push 105
	jmp DefaultInterruptWrapper
global InterruptWrapper106
InterruptWrapper106:
	push 106
	jmp DefaultInterruptWrapper
global InterruptWrapper107
InterruptWrapper107:
	push 107
	jmp DefaultInterruptWrapper
global InterruptWrapper108
InterruptWrapper108:
	push 108
	jmp DefaultInterruptWrapper
global InterruptWrapper109
InterruptWrapper109:
	push 109
	jmp DefaultInterruptWrapper
global InterruptWrapper110
InterruptWrapper110:
	push 110
	jmp DefaultInterruptWrapper
global InterruptWrapper111
InterruptWrapper111:
	push 111
	jmp DefaultInterruptWrapper
global InterruptWrapper112
InterruptWrapper112:
	push 112
	jmp DefaultInterruptWrapper
global InterruptWrapper113
InterruptWrapper113:
	push 113
	jmp DefaultInterruptWrapper
global InterruptWrapper114
InterruptWrapper114:
	push 114
	jmp DefaultInterruptWrapper
global InterruptWrapper115
InterruptWrapper115:
	push 115
	jmp DefaultInterruptWrapper
global InterruptWrapper116
InterruptWrapper116:
	push 116
	jmp DefaultInterruptWrapper
global InterruptWrapper117
InterruptWrapper117:
	push 117
	jmp DefaultInterruptWrapper
global InterruptWrapper118
InterruptWrapper118:
	push 118
	jmp DefaultInterruptWrapper
global InterruptWrapper119
InterruptWrapper119:
	push 119
	jmp DefaultInterruptWrapper
global InterruptWrapper120
InterruptWrapper120:
	push 120
	jmp DefaultInterruptWrapper
global InterruptWrapper121
InterruptWrapper121:
	push 121
	jmp DefaultInterruptWrapper
global InterruptWrapper122
InterruptWrapper122:
	push 122
	jmp DefaultInterruptWrapper
global InterruptWrapper123
InterruptWrapper123:
	push 123
	jmp DefaultInterruptWrapper
global InterruptWrapper124
InterruptWrapper124:
	push 124
	jmp DefaultInterruptWrapper
global InterruptWrapper125
InterruptWrapper125:
	push 125
	jmp DefaultInterruptWrapper
global InterruptWrapper126
InterruptWrapper126:
	push 126
	jmp DefaultInterruptWrapper
global InterruptWrapper127
InterruptWrapper127:
	push 127
	jmp DefaultInterruptWrapper
global InterruptWrapper128
InterruptWrapper128:
	push 128
	jmp DefaultInterruptWrapper
global InterruptWrapper129
InterruptWrapper129:
	push 129
	jmp DefaultInterruptWrapper
global InterruptWrapper130
InterruptWrapper130:
	push 130
	jmp DefaultInterruptWrapper
global InterruptWrapper131
InterruptWrapper131:
	push 131
	jmp DefaultInterruptWrapper
global InterruptWrapper132
InterruptWrapper132:
	push 132
	jmp DefaultInterruptWrapper
global InterruptWrapper133
InterruptWrapper133:
	push 133
	jmp DefaultInterruptWrapper
global InterruptWrapper134
InterruptWrapper134:
	push 134
	jmp DefaultInterruptWrapper
global InterruptWrapper135
InterruptWrapper135:
	push 135
	jmp DefaultInterruptWrapper
global InterruptWrapper136
InterruptWrapper136:
	push 136
	jmp DefaultInterruptWrapper
global InterruptWrapper137
InterruptWrapper137:
	push 137
	jmp DefaultInterruptWrapper
global InterruptWrapper138
InterruptWrapper138:
	push 138
	jmp DefaultInterruptWrapper
global InterruptWrapper139
InterruptWrapper139:
	push 139
	jmp DefaultInterruptWrapper
global InterruptWrapper140
InterruptWrapper140:
	push 140
	jmp DefaultInterruptWrapper
global InterruptWrapper141
InterruptWrapper141:
	push 141
	jmp DefaultInterruptWrapper
global InterruptWrapper142
InterruptWrapper142:
	push 142
	jmp DefaultInterruptWrapper
global InterruptWrapper143
InterruptWrapper143:
	push 143
	jmp DefaultInterruptWrapper
global InterruptWrapper144
InterruptWrapper144:
	push 144
	jmp DefaultInterruptWrapper
global InterruptWrapper145
InterruptWrapper145:
	push 145
	jmp DefaultInterruptWrapper
global InterruptWrapper146
InterruptWrapper146:
	push 146
	jmp DefaultInterruptWrapper
global InterruptWrapper147
InterruptWrapper147:
	push 147
	jmp DefaultInterruptWrapper
global InterruptWrapper148
InterruptWrapper148:
	push 148
	jmp DefaultInterruptWrapper
global InterruptWrapper149
InterruptWrapper149:
	push 149
	jmp DefaultInterruptWrapper
global InterruptWrapper150
InterruptWrapper150:
	push 150
	jmp DefaultInterruptWrapper
global InterruptWrapper151
InterruptWrapper151:
	push 151
	jmp DefaultInterruptWrapper
global InterruptWrapper152
InterruptWrapper152:
	push 152
	jmp DefaultInterruptWrapper
global InterruptWrapper153
InterruptWrapper153:
	push 153
	jmp DefaultInterruptWrapper
global InterruptWrapper154
InterruptWrapper154:
	push 154
	jmp DefaultInterruptWrapper
global InterruptWrapper155
InterruptWrapper155:
	push 155
	jmp DefaultInterruptWrapper
global InterruptWrapper156
InterruptWrapper156:
	push 156
	jmp DefaultInterruptWrapper
global InterruptWrapper157
InterruptWrapper157:
	push 157
	jmp DefaultInterruptWrapper
global InterruptWrapper158
InterruptWrapper158:
	push 158
	jmp DefaultInterruptWrapper
global InterruptWrapper159
InterruptWrapper159:
	push 159
	jmp DefaultInterruptWrapper
global InterruptWrapper160
InterruptWrapper160:
	push 160
	jmp DefaultInterruptWrapper
global InterruptWrapper161
InterruptWrapper161:
	push 161
	jmp DefaultInterruptWrapper
global InterruptWrapper162
InterruptWrapper162:
	push 162
	jmp DefaultInterruptWrapper
global InterruptWrapper163
InterruptWrapper163:
	push 163
	jmp DefaultInterruptWrapper
global InterruptWrapper164
InterruptWrapper164:
	push 164
	jmp DefaultInterruptWrapper
global InterruptWrapper165
InterruptWrapper165:
	push 165
	jmp DefaultInterruptWrapper
global InterruptWrapper166
InterruptWrapper166:
	push 166
	jmp DefaultInterruptWrapper
global InterruptWrapper167
InterruptWrapper167:
	push 167
	jmp DefaultInterruptWrapper
global InterruptWrapper168
InterruptWrapper168:
	push 168
	jmp DefaultInterruptWrapper
global InterruptWrapper169
InterruptWrapper169:
	push 169
	jmp DefaultInterruptWrapper
global InterruptWrapper170
InterruptWrapper170:
	push 170
	jmp DefaultInterruptWrapper
global InterruptWrapper171
InterruptWrapper171:
	push 171
	jmp DefaultInterruptWrapper
global InterruptWrapper172
InterruptWrapper172:
	push 172
	jmp DefaultInterruptWrapper
global InterruptWrapper173
InterruptWrapper173:
	push 173
	jmp DefaultInterruptWrapper
global InterruptWrapper174
InterruptWrapper174:
	push 174
	jmp DefaultInterruptWrapper
global InterruptWrapper175
InterruptWrapper175:
	push 175
	jmp DefaultInterruptWrapper
global InterruptWrapper176
InterruptWrapper176:
	push 176
	jmp DefaultInterruptWrapper
global InterruptWrapper177
InterruptWrapper177:
	push 177
	jmp DefaultInterruptWrapper
global InterruptWrapper178
InterruptWrapper178:
	push 178
	jmp DefaultInterruptWrapper
global InterruptWrapper179
InterruptWrapper179:
	push 179
	jmp DefaultInterruptWrapper
global InterruptWrapper180
InterruptWrapper180:
	push 180
	jmp DefaultInterruptWrapper
global InterruptWrapper181
InterruptWrapper181:
	push 181
	jmp DefaultInterruptWrapper
global InterruptWrapper182
InterruptWrapper182:
	push 182
	jmp DefaultInterruptWrapper
global InterruptWrapper183
InterruptWrapper183:
	push 183
	jmp DefaultInterruptWrapper
global InterruptWrapper184
InterruptWrapper184:
	push 184
	jmp DefaultInterruptWrapper
global InterruptWrapper185
InterruptWrapper185:
	push 185
	jmp DefaultInterruptWrapper
global InterruptWrapper186
InterruptWrapper186:
	push 186
	jmp DefaultInterruptWrapper
global InterruptWrapper187
InterruptWrapper187:
	push 187
	jmp DefaultInterruptWrapper
global InterruptWrapper188
InterruptWrapper188:
	push 188
	jmp DefaultInterruptWrapper
global InterruptWrapper189
InterruptWrapper189:
	push 189
	jmp DefaultInterruptWrapper
global InterruptWrapper190
InterruptWrapper190:
	push 190
	jmp DefaultInterruptWrapper
global InterruptWrapper191
InterruptWrapper191:
	push 191
	jmp DefaultInterruptWrapper
global InterruptWrapper192
InterruptWrapper192:
	push 192
	jmp DefaultInterruptWrapper
global InterruptWrapper193
InterruptWrapper193:
	push 193
	jmp DefaultInterruptWrapper
global InterruptWrapper194
InterruptWrapper194:
	push 194
	jmp DefaultInterruptWrapper
global InterruptWrapper195
InterruptWrapper195:
	push 195
	jmp DefaultInterruptWrapper
global InterruptWrapper196
InterruptWrapper196:
	push 196
	jmp DefaultInterruptWrapper
global InterruptWrapper197
InterruptWrapper197:
	push 197
	jmp DefaultInterruptWrapper
global InterruptWrapper198
InterruptWrapper198:
	push 198
	jmp DefaultInterruptWrapper
global InterruptWrapper199
InterruptWrapper199:
	push 199
	jmp DefaultInterruptWrapper
global InterruptWrapper200
InterruptWrapper200:
	push 200
	jmp DefaultInterruptWrapper
global InterruptWrapper201
InterruptWrapper201:
	push 201
	jmp DefaultInterruptWrapper
global InterruptWrapper202
InterruptWrapper202:
	push 202
	jmp DefaultInterruptWrapper
global InterruptWrapper203
InterruptWrapper203:
	push 203
	jmp DefaultInterruptWrapper
global InterruptWrapper204
InterruptWrapper204:
	push 204
	jmp DefaultInterruptWrapper
global InterruptWrapper205
InterruptWrapper205:
	push 205
	jmp DefaultInterruptWrapper
global InterruptWrapper206
InterruptWrapper206:
	push 206
	jmp DefaultInterruptWrapper
global InterruptWrapper207
InterruptWrapper207:
	push 207
	jmp DefaultInterruptWrapper
global InterruptWrapper208
InterruptWrapper208:
	push 208
	jmp DefaultInterruptWrapper
global InterruptWrapper209
InterruptWrapper209:
	push 209
	jmp DefaultInterruptWrapper
global InterruptWrapper210
InterruptWrapper210:
	push 210
	jmp DefaultInterruptWrapper
global InterruptWrapper211
InterruptWrapper211:
	push 211
	jmp DefaultInterruptWrapper
global InterruptWrapper212
InterruptWrapper212:
	push 212
	jmp DefaultInterruptWrapper
global InterruptWrapper213
InterruptWrapper213:
	push 213
	jmp DefaultInterruptWrapper
global InterruptWrapper214
InterruptWrapper214:
	push 214
	jmp DefaultInterruptWrapper
global InterruptWrapper215
InterruptWrapper215:
	push 215
	jmp DefaultInterruptWrapper
global InterruptWrapper216
InterruptWrapper216:
	push 216
	jmp DefaultInterruptWrapper
global InterruptWrapper217
InterruptWrapper217:
	push 217
	jmp DefaultInterruptWrapper
global InterruptWrapper218
InterruptWrapper218:
	push 218
	jmp DefaultInterruptWrapper
global InterruptWrapper219
InterruptWrapper219:
	push 219
	jmp DefaultInterruptWrapper
global InterruptWrapper220
InterruptWrapper220:
	push 220
	jmp DefaultInterruptWrapper
global InterruptWrapper223
InterruptWrapper223:
	push 223
	jmp DefaultInterruptWrapper
global InterruptWrapper224
InterruptWrapper224:
	push 224
	jmp DefaultInterruptWrapper
global InterruptWrapper225
InterruptWrapper225:
	push 225
	jmp DefaultInterruptWrapper
global InterruptWrapper226
InterruptWrapper226:
	push 226
	jmp DefaultInterruptWrapper
global InterruptWrapper227
InterruptWrapper227:
	push 227
	jmp DefaultInterruptWrapper
global InterruptWrapper228
InterruptWrapper228:
	push 228
	jmp DefaultInterruptWrapper
global InterruptWrapper229
InterruptWrapper229:
	push 229
	jmp DefaultInterruptWrapper
global InterruptWrapper230
InterruptWrapper230:
	push 230
	jmp DefaultInterruptWrapper
global InterruptWrapper231
InterruptWrapper231:
	push 231
	jmp DefaultInterruptWrapper
global InterruptWrapper232
InterruptWrapper232:
	push 232
	jmp DefaultInterruptWrapper
global InterruptWrapper233
InterruptWrapper233:
	push 233
	jmp DefaultInterruptWrapper
global InterruptWrapper234
InterruptWrapper234:
	push 234
	jmp DefaultInterruptWrapper
global InterruptWrapper235
InterruptWrapper235:
	push 235
	jmp DefaultInterruptWrapper
global InterruptWrapper236
InterruptWrapper236:
	push 236
	jmp DefaultInterruptWrapper
global InterruptWrapper237
InterruptWrapper237:
	push 237
	jmp DefaultInterruptWrapper
global InterruptWrapper238
InterruptWrapper238:
	push 238
	jmp DefaultInterruptWrapper
global InterruptWrapper239
InterruptWrapper239:
	push 239
	jmp DefaultInterruptWrapper
global InterruptWrapper240
InterruptWrapper240:
	push 240
	jmp DefaultInterruptWrapper
global InterruptWrapper241
InterruptWrapper241:
	push 241
	jmp DefaultInterruptWrapper
global InterruptWrapper242
InterruptWrapper242:
	push 242
	jmp DefaultInterruptWrapper
global InterruptWrapper243
InterruptWrapper243:
	push 243
	jmp DefaultInterruptWrapper
global InterruptWrapper244
InterruptWrapper244:
	push 244
	jmp DefaultInterruptWrapper
global InterruptWrapper245
InterruptWrapper245:
	push 245
	jmp DefaultInterruptWrapper
global InterruptWrapper246
InterruptWrapper246:
	push 246
	jmp DefaultInterruptWrapper
global InterruptWrapper247
InterruptWrapper247:
	push 247
	jmp DefaultInterruptWrapper
global InterruptWrapper248
InterruptWrapper248:
	push 248
	jmp DefaultInterruptWrapper
global InterruptWrapper249
InterruptWrapper249:
	push 249
	jmp DefaultInterruptWrapper
global InterruptWrapper250
InterruptWrapper250:
	push 250
	jmp DefaultInterruptWrapper
global InterruptWrapper251
InterruptWrapper251:
	push 251
	jmp DefaultInterruptWrapper
global InterruptWrapper252
InterruptWrapper252:
	push 252
	jmp DefaultInterruptWrapper
global InterruptWrapper253
InterruptWrapper253:
	push 253
	jmp DefaultInterruptWrapper
global InterruptWrapper254
InterruptWrapper254:
	push 254
	jmp DefaultInterruptWrapper
global InterruptWrapper255
InterruptWrapper255:
	push 255
	jmp DefaultInterruptWrapper