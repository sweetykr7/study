import { Injectable } from '@nestjs/common';
import { SignInDto } from './signin.dto';
import { SignUpDto } from './signup.dto';
import { ResponseDto } from './response.dto';

@Injectable()
export class LoginService {
  saveInformation: SignUpDto[] = [];

  signUp(signUpDto: SignUpDto): ResponseDto {
    this.saveInformation.push(signUpDto);
    return this.createResponseDto('success');
  }

  signIn(signInDto: SignInDto): string {
    for (let index = 0; index < this.saveInformation.length; index++) {
      if (
        signInDto.email == this.saveInformation[index].email &&
        signInDto.password == this.saveInformation[index].password
      )
        return 'success';
    }
    return 'fail';
  }

  createResponseDto(result: string): ResponseDto {
    const res = { result: result, token: 'tokenTest1234' } as ResponseDto;
    return res;
  }
}
