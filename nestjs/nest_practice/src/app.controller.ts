import {
  Controller,
  Get,
  Post,
  Body,
  UsePipes,
  ValidationPipe,
} from '@nestjs/common';
import { AppService } from './app.service';
import { SignUpDto } from './signup.dto';
import { SignInDto } from './signin.dto';
import { LoginService } from './login.service';
import { ResponseDto } from './response.dto';

@Controller()
export class AppController {
  constructor(private readonly appService: AppService) {}

  @Get('/index')
  getHello(): string {
    return this.appService.getHello(`Hello.`);
  }
}

@Controller()
export class LoginController {
  constructor(private readonly loginService: LoginService) {}

  @Post('signup')
  signUp(@Body() signUpDto: SignUpDto): ResponseDto {
    return this.loginService.signUp(signUpDto);
  }
  @Post('signin')
  @UsePipes(ValidationPipe)
  signIn(@Body() signInDto: SignInDto): string {
    return this.loginService.signIn(signInDto);
  }
}
